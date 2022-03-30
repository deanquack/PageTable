#ifndef PAGETABLE_H
#define PAGETABLE_H


#include <stdlib.h>

#define levelPtr 256
using namespace std;

struct pageTable{ 
    unsigned int levelCount; 
    unsigned int bitmask;
    unsigned int bitShift;
    unsigned int entryCount;
};

struct level{
    unsigned int depth = 0;
    pageTable *pageTablePtr;
    level *nextLevelPtr[levelPtr];
    unsigned int map[];
};

struct Map{
    unsigned int frame;
    bool validBit;
};

void pageInsert(pageTable *pagetable, unsigned int virtualAddress, unsigned int frame);
unsigned int virtualAddressToPageNum(unsigned int virtualAddress, unsigned int mask, unsigned int shift);
Map* pageLookup(pageTable *pagetable, unsigned int virtualAddress);
Map* map(unsigned int frame, bool ValidBit);
#endif