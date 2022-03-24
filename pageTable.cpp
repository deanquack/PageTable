/*CS480, Spring 2022
Assignment #3, Paging with Multilevel Page table and TLB
FILE: pageTable.cpp
Dean Quach, cssc1445 & Gian Kyle Nicolas, csscXXXX
Copyright (c) 2022 Dean Quach. Gian Nicolas. All rights reserved.
*/

#include "tracereader.c"
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
using namespace std;

//constructor for creating the node. 
pageTable* node(){
    pageTable* tmp = new pageTable();
    return tmp;
}

/*Given a virtual address, apply the given bit mask and shift right by the
given number of bits. Returns the virtual page number. This function can
be used to access the page number of any level by supplying the
appropriate parameters.*/
int virtualAddressToPageNum ( unsigned int virtualAddress, unsigned int mask, unsigned int shift)
{
    unsigned int vAddr = virtualAddress;
    unsigned int bitMask = bitmask(vAddr, mask, shift); //call helper function to bitmask the virtual Address and the mask
    unsigned int virtualPageNum = bitMask;
    return virtualPageNum;
}

//insert the pagetable
void pageInsert(pageTable *pagetable, unsigned int virtualAddress, unsigned int frame){
    pageTable* head = new pageTable;
    while(head->levelCount[&frame] != 28){
        if(virtualAddress[&frame] != 0){ //checks if the address is in the page 
            pageTable* newNode = node();
        }
        frame++; //increments to the next address
        virtualAddressToPageNum (head, virtualAddress, mask, shift); //convert virtual address found to physical frame number
        pageInsert(pageTable, virtualAddress, frame);
    } 
}


level* pageLookup(pageTable *pagetable, unsigned int virtualAddress){
    
    return NULL;
}

//helper function that bitmasks the offset coming from the virtual address
unsigned int bitmask(unsigned VirtualAddress, unsigned int mask, unsigned int shift){
    unsigned int mask = 32 - shift; //the mask is gotten by the 32 bits subtracted by the size of bits
    unsigned int offset = 0;
    return offset = VirtualAddress & mask;
}


