#ifndef PAGETABLE_H
#define PAGETABLE_H

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
#define levelPtr 256
using namespace std;

/*typedef struct pageTable{ 
    unsigned int levelCount; 
    unsigned int bitmask;
    unsigned int bitShift;
    unsigned int entryCount;
}pageTable;

typedef struct level{
    unsigned int depth = 0;
    //pageTable *pageTablePtr;
    level *nextLevelPtr[levelPtr];
    unsigned int map[];
};*/

//void pageInsert(pageTable *pagetable, unsigned int virtualAddress, unsigned int frame);
unsigned int virtualAddressToPageNum (unsigned int virtualAddress, unsigned int mask, unsigned int shift);





#endif