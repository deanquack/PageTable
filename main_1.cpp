/*CS480, Spring 2022
Assignment #3, Paging with Multilevel Page table and TLB
FILE: main.cpp
Dean Quach, cssc1445 & Gian Kyle Nicolas, csscXXXX
Copyright (c) 2022 Dean Quach. Gian Nicolas. All rights reserved.
*/

#include "tracereader.c"
#include "output_mode_helpers.cpp"
//#include "pageTable.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include "string.h"
#include <iomanip>
#include <cstring>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <io.h>
#include <unistd.h>
#include <math.h>
using namespace std;

main(int argc, char** argv){

    int option;
    bool BADFLAG = false;
    int numOfProcesses;
    int cache = 0;
    //pageTable *pagetable = new pageTable();
    unsigned int bitMasks = 0x0FF0000; //used for bitmasking
    //level *lvlPtr = new level();
    p2AddrTr ptr;
    unsigned int pageNum = 0;
    unsigned int vAddr;
    unsigned int frame = 0;
    unsigned int levels = 0;
    unsigned int shift = 24;
    OutputOptionsType *report = new OutputOptionsType();
    //report->bitmasks = false;
    report->offset = false;
    //report->summary = false;
    //report->v2p_tlb_pt = false;
    report->virtual2physical = false;
    //report->vpn2pfn = false;
    

    while ( (option = getopt(argc, argv, "n:c:o:")) != -1) {
        switch (option){
            case 'n':
                numOfProcesses = atoi(optarg);
                break;
            case 'c':
                if(cache < 0){
                    cerr << "Cache capacity must be a number, greater than or equal to 0" << endl;
                    exit(1);
                }
                else{
                    cache = atoi(optarg);
                    //cout << cacheTLB << endl;
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
                    //report->v2p_tlb_pt = true;
                    //report_v2pUsingTLB_PTwalk(uint32_t src, uint32_t dest, bool tlbhit, bool pthit);
                }
                else if(strcmp("vpn2pfn", optarg)== 0){
                    //report->vpn2pfn = true;
                    //report_pagemap(level, *pages, frame);
                }
                else if(strcmp("summary", optarg)== 0){
                    //report->summary = true;
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
    while(idx < argc){

        //cout << atoi(argv[idx]) << endl;
        byteSize += atoi(argv[idx]);
        idx++;
        //levels = idx - 3;
    }
    //cout << levels << endl;
    FILE* trace2 = fopen("trace.tr", "r");
    cout << byteSize << endl;
    int offset = 32 - byteSize; //the offest is gotten by the 32 bits subtracted by the size of bits
    int page = pow(2,(offset));
    //printf("Page byte size: %d bytes\n", page);

    for(int i = 0; i < numOfProcesses; i++){ 
        //while (!feof(trace2)){ // iterate over trace file
            if(NextAddress(trace2, &ptr)){
                vAddr = ptr.addr;
                unsigned int page = vAddr & bitMasks;
                unsigned int offset = page;
                unsigned int pageAddr = page >> shift;
                //printf("%08X -> %p\n", vAddr, page);
                if(report->virtual2physical == true){
                    report_virtual2physical(vAddr, page);
                }
                if(report->offset == true){
                    hexnum(page);
                    cout << std::flush;
                }
                if(report->summary == true){
                //    report_summary(unsigned int page_size, unsigned int cacheHits,unsigned int pageTableHits,unsigned int addresses, unsigned int frames_used,unsigned int bytes);
                }
                if(report->bitmasks == true){
                    //report_bitmasks(levels, bitMasks);
                }
                //pageNum = virtualAddressToPageNum(vAddr, mask, offset); //bitmask and shift
                //cout << pageNum << endl;
                //pageInsert(pagetable, vAddr, frame);
            }
        //}
    }
}

//next up implement getopt
//pull necessary bits determined by args

//you need main, split the pagetable operation for insert and search(can be in one file, if not maybe two), and tlb
//main datastructures: pageTable (multi paging level setup), node is "Level", 