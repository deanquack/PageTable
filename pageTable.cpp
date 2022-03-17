/*CS480, Spring 2022
Assignment #3, Paging with Multilevel Page table and TLB
FILE: pageTable.cpp
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
using namespace std;

//constructor for creating the node. 
pageTable* node(){
    pageTable* tmp = new pageTable();
    return tmp;
}

//insert the pagetable
void pageInsert(pageTable *pagetable, unsigned int virtualAddress, unsigned int frame){
    pageTable* head = pagetable;
    level* map->
    head->entryCount[];
    head->levelCount;
    head->bitShift[];
    head->
    while(virtualAddress[frame] != 0){
        int index = virtualAddressToPageNum (virtualAddress, mask, shift); 
        if(virtualAddress[frame] == 0){
            pageTable* newNode = level->map;
            head->levelCount[frame] = newNode;
        }
        frame++; 
    }
    
}


Map* pageLookup(pageTable *pagetable, unsigned int virtualAddress){
    
    return NULL;
}

/*Given a virtual address, apply the given bit mask and shift right by the
given number of bits. Returns the virtual page number. This function can
be used to access the page number of any level by supplying the
appropriate parameters.*/
unsigned int virtualAddressToPageNum (unsigned int virtualAddress, unsigned int mask, unsigned int shift){
    int virtualPageNum = 0;

    return virtualPageNum;
}

