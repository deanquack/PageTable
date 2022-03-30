/*CS480, Spring 2022
Assignment #3, Paging with Multilevel Page table and TLB
FILE: pageTable.cpp
Dean Quach, cssc1445 & Gian Kyle Nicolas, cssc1438
Copyright (c) 2022 Dean Quach. Gian Nicolas. All rights reserved.
*/

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
#include "math.h"
using namespace std;

//this is the constructor for the pageTable
pageTable* pagetable(unsigned int level, unsigned int bitLevels, int numOfbits){
    unsigned int address = 0;
    unsigned int frame = 0;
    unsigned int byteSize = 0;
    unsigned int levelCount = level;
    unsigned int pageSize = (unsigned int)pow(2, (32 - numOfbits)); 
    unsigned int bitsPerLevel = bitLevels;
}
//insert the pagetablem if virtual address is found, then 
void pageInsert(pageTable *pagetable, unsigned int virtualAddress, unsigned int frame){
    pageTable* head = new pageTable();
    unsigned int vAddr = virtualAddress;
    unsigned int mask = head->bitmask[&frame];
    unsigned int shift = head->bitShift[&frame];
    int index = virtualAddressToPageNum(virtualAddress, mask, shift);
    while(head->levelCount[&frame] != 28){
        /*if(virtualAddress[&frame] != 0){ //checks if the address is in the page 
           // pageTable* newNode = node();
        }*/
        //frame++; //increments to the next address
        //virtualAddressToPageNum (head, virtualAddress, mask, shift); //convert virtual address found to physical frame number
        //pageInsert(pageTable, virtualAddress, frame);
    } 
}


Map* pageLookup(pageTable *pagetable, unsigned int virtualAddress){
    unsigned int shift = shift;
    return NULL;
}

Map* map(unsigned int frame, bool ValidBit){
    frame = 0;
    ValidBit = false;
}

unsigned int virtualAddressToPageNum(unsigned int virtualAddress, unsigned int mask, unsigned int shift){
    unsigned int pageNumber;
    pageNumber = virtualAddress & mask;
    pageNumber = pageNumber >> shift;
    return pageNumber;
}
