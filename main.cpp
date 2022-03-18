/*CS480, Spring 2022
Assignment #3, Paging with Multilevel Page table and TLB
FILE: main.cpp
Dean Quach, cssc1445 & Gian Kyle Nicolas, csscXXXX
Copyright (c) 2022 Dean Quach. Gian Nicolas. All rights reserved.
*/

#include "tracereader.cpp"
//#include "output_mode_helpers.h"
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
//#include <unistd.h>
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
    FILE* trace2 = fopen("trace.tr", "r");

    if(NextAddress(trace2, &ptr)){
        vAddr = ptr.addr;
        cout << vAddr << endl;
    }    
    while (!feof(trace2)){ // iterate over trace file 
        if(NextAddress(trace2, &ptr)){
            vAddr = ptr.addr;
            printf("%d \n", vAddr);
            //pageInsert(pageTable, vAddr, frame);
        }
    }
}
