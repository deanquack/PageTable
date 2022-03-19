/*CS480, Spring 2022
Assignment #3, Paging with Multilevel Page table and TLB
FILE: main.cpp
Dean Quach, cssc1445 & Gian Kyle Nicolas, csscXXXX
Copyright (c) 2022 Dean Quach. Gian Nicolas. All rights reserved.
*/

#include "tracereader.c"
#include "output_mode_helpers.h"
//#include "pageTable.cpp"
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

    //pageTable page;
    //OutputOptionsType* opt;

    int option;
    bool BADFLAG = false;
    int numOfProcesses = 0;
    int cacheTLB;
    //pageTable *pagetable = new pageTable();
    p2AddrTr ptr;
    unsigned int vAddr;
    unsigned int frame = 0;
    unsigned int mask = 0x00000FFF;
    unsigned int shift = 24;
    FILE* trace2 = fopen("trace.tr", "r");

    while()

    while (!feof(trace2)){ // iterate over trace file 
        if(NextAddress(trace2, &ptr)){
            vAddr = ptr.addr;
            unsigned int page = vAddr & mask;
            unsigned int pageAddr = page >> shift;
            printf("%08X -> %p\n", vAddr, page);
        //  virtualAddressToPageNum(vAddr, mask, shift); //bitmask and shift
            //pageInsert(pageTable, vAddr, frame);
        }
    }
}

//next up implement getopt
//pull necessary bits determined by args

//you need main, split the pagetable operation for insert and search(can be in one file, if not maybe two), and tlb
//main datastructures: pageTable (multi paging level setup), node is "Level", 