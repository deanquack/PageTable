/*CS480, Spring 2022
Assignment #3, Paging with Multilevel Page table and TLB
FILE: main.cpp
Dean Quach, cssc1445 & Gian Kyle Nicolas, cssc1438
Copyright (c) 2022 Dean Quach. Gian Nicolas. All rights reserved.
*/

#include "tracereader.cpp"
#include "output_mode_helpers.cpp"
#include "pageTable.h"
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "math.h"
#include <string.h>
using namespace std;


int main(int argc, char** argv){
    int option;
    bool BADFLAG = false;
    int numOfProcesses;
    unsigned int LRU = 10; //accesses the most recent 10 physical addresses in the page 
    int cacheTLB = 0;
    //pageTable *pagetable = new pageTable();
    p2AddrTr *ptr = new p2AddrTr();
    unsigned int pageNum = 0;
    unsigned int vAddr; //thsi value helps parse through the trace file
    unsigned int frame = 0;
    unsigned int shift;
    OutputOptionsType *report = new OutputOptionsType(); //obtains the datastructure for the output functions

    
    //checks the optional arguments
    while ( (option = getopt(argc, argv, "n:c:o:")) != -1) {
        switch (option){
            case 'n':
                numOfProcesses = atoi(optarg);
                break;
            case 'c':
                if(cacheTLB < 0){
                    cerr << "Cache capacity must be a number, greater than or equal to 0" << endl;
                    exit(1);
                }
            case 'o':
                if(strcmp("bitmasks", optarg)== 0){
                    report->bitmasks = true;
                    //report_bitmasks(levels, masks);
                }
                else if(strcmp("virtual2physical", optarg)== 0){
                    report->virtual2physical = true;
                }
                else if(strcmp("v2p_tlb_pt", optarg)== 0){
                    report->v2p_tlb_pt = true;
                    //report_v2pUsingTLB_PTwalk(uint32_t src, uint32_t dest, bool tlbhit, bool pthit);
                }
                else if(strcmp("vpn2pfn", optarg)== 0){
                    report->vpn2pfn = true;
                    //report_pagemap(level, *pages, frame);
                }
                else if(strcmp("summary", optarg)== 0){
                    report->summary = true;
                    //report_summary();
                }
                else if(strcmp("offset", optarg)== 0){
                    report->offset = true;
                }
                break;
            default:
                exit(1);  
        }    
    }

    int idx = optind + 1;
    int byteSize = 0;
    //this loop will obtain the necessary mandatory arguments after checking the optargs
    while(idx < argc){ 
        byteSize += atoi(argv[idx]);
        idx++;
        if(byteSize > 28){ //checks if the amount of bytes per page sent in command line is less than 28
            cout << "Too many bits used in page tables" << endl;
            exit(1);
        }
    }
    const char* fp2 = argv[optind];
    FILE* trace2 = fopen(fp2, "r"); //this will open the trace file
    //checks for the bad tracefile
    if(!trace2){
        std::cerr << "Unable to open <<" << argv[optind] << ">>" << endl;
        exit(1);
    }
    int level = (argc - 1) - optind; // the number of levels in the arguments stated after the treace file
    unsigned int bitLevels[level];
    int numberOfBits = 0;
    for(int i = 0; i < level; i++){
        bitLevels[i] = atoi(argv[optind + i + 1]); //set each bit level to the appropriate index
        numberOfBits += bitLevels[i]; //checks the number of bits per level
    }
    
    uint32_t masks = 0x00000FFF; //place holder for the actual mask value
    
    
    unsigned int offset = 32 - byteSize; //the offest is gotten by the 32 bits subtracted by the size of bits
    int page = pow(2,(offset));

    shift = byteSize; //gets the shift needed to move the virtual address after getting the offset
    
    if(numOfProcesses < 0){ //this will occur if case -n is not specififed
        while (!feof(trace2)){ // iterate over trace file
            if(NextAddress(trace2, ptr)){
                vAddr = ptr->addr;
                //bitwise masking operations
                //this is will take in the virtual address found in the tracefile and convert to a physical Address 
                unsigned int page = vAddr & masks;
                unsigned int offset = page;
                unsigned int physicalAddr = page << shift;
                physicalAddr = physicalAddr >> shift;
              
                // these cases will check if the optional arguments are true and print out the right output
                if(report->virtual2physical == true){
                    report_virtual2physical(vAddr, physicalAddr);
                }
                if(report->offset == true){
                    hexnum(page);
                    cout << std::flush;
                }
                if(report->bitmasks == true){
                    report_bitmasks(level, &masks);
                    break;
                }
                //if(report->summary == true){
                //    report_summary(unsigned int page_size, unsigned int cacheHits,unsigned int pageTableHits,unsigned int addresses, unsigned int frames_used,unsigned int bytes);
                //    break;
                //}
            }
        }
    }
    else{ //this will occur if case -n is specified
       for(int i = 0; i < numOfProcesses; i++){ //loop through all of the num of processes defined 
            if(NextAddress(trace2, ptr)){
                vAddr = ptr->addr;// this will obtain the virtual address 
                //bitwise masking operations
                unsigned int page = vAddr & masks;
                unsigned int offset = page;
                unsigned int physicalAddr = page << shift;
                physicalAddr = physicalAddr >> shift;

                // these cases will check if the optional arguments are true and print out the right output
                if(report->virtual2physical == true){//print the virtual2physcial output
                    report_virtual2physical(vAddr, physicalAddr);
                }
                else if(report->offset == true){//prints the offset output
                    hexnum(page);
                    cout << std::flush;
                }
                else if(report->bitmasks == true){
                    report_bitmasks(level, &masks);
                    break; //this will make it so that when "bitmasks" is an optarg, it stops the loop
                }
                //if(report->summary == true){
                //    report_summary(unsigned int page_size, unsigned int cacheHits,unsigned int pageTableHits,unsigned int addresses, unsigned int frames_used,unsigned int bytes);
                //}
                else{
                    std::cout << "Invalid Output Mode" << endl;
                    exit(1);
                }
                //pageInsert(pagetable, vAddr, frame);
            } 
        }
    }
    fclose(trace2);
}

//you need main, split the pagetable operation for insert and search(can be in one file, if not maybe two), and tlb
//main datastructures: pageTable (multi paging level setup), node is "Level", 