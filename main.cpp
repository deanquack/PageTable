/*CS480, Spring 2022
Assignment #3, Paging with Multilevel Page table and TLB
FILE: main.cpp
Dean Quach, cssc1445 & Gian Kyle Nicolas, csscXXXX
Copyright (c) 2022 Dean Quach. Gian Nicolas. All rights reserved.
*/

#include "tracereader.h"
#include "output_mode_helpers.h"
#include "pageTable.h"
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
using namespace std;

main(int argc, char** argv){

    pageTable* page = new pageTable();
    p2AddrTr mtrace;
    unsigned int vAddr;
    FILE* tracef_h;
    if(NextAddress(tracef_h, & mtrace)){ //tracef_h - file handle from fopen
        vAddr = mtrace.addr;
    } 
    //default values for main
    int option;
    bool BADFLAG = false;
    int numOfProcesses = 0;
    int cacheTLB;

    //optional arguments
    while ( (option = getopt(argc, argv, "n:c:o:")) != -1) { 
        switch(option){
            case 'n': /* Number of addresses to process */
                numOfProcesses =(atoi(optarg);
                break;
            case 'c': /* produce map of pages */
               if(cacheTLB < 0){
                   cout << "Cache capacity must be a number, greater than or equal to 0" << endl;
                   exit(1);
               }
               else if (cacheTLB == 0){
                   cacheTLB = 0;
               }
               else{
                   cacheTLB  = (atoi(optarg);
               }
                break;
            case 'o': //Mode is a string that specifies what to be printed to the standard output:
               if(optarg = "vpn2pfn"){ 
               /*For every virtual address, show its virtual page numbers
                for each level followed by the frame number, one address per
                line. (Use report_pagemap.)*/
                report_pagemap(levels, pages, frame);
               }
               else if (optarg = "v2p_tlb_pt"){
               /*Show virtual to physical translation for every address,
                lookup TLB then pagetable walk if TLB misses, one address
                translation per line. (Use report_v2pUsingTLB_PTwalk.)*/
                report_v2pUsingTLB_PTwalk;

               }
               else if(optarg = "bitmasks"){
                /*Write out the bitmasks for each level starting with the
                highest level, one per line. In this mode, you do not need to
                actually process any addresses. Program prints bitmasks and
                exits. (Use report_bitmasks.)*/          

               }
               else if(optarg = "virtual2physical"){
                /*Show virtual address translation to physical
                address for every address, one address translation per line.
                (Use report_virtual2physical.)*/
                

               }
               else if(optarg = "offset"){ /* Show offsets of virtual addresses, one address offset per line. (Use hexnum.)*/
                    
               }
                break;
            default: //assuming it's a bad case
                exit(BADFLAG);      
        }   
    }
    printf("%d", );

}