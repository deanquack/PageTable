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

pageTable* node(); //make a pageTable pointer node
void pageInsert(pageTable *pagetable, unsigned int virtualAddress, unsigned int frame);
int virtualAddressToPageNum (pageTable *pagetable, unsigned int virtualAddress, unsigned int mask, unsigned int shift);
level pageLookup();
unsigned int bitmask(unsigned VirtualAddress, unsigned int mask, unsigned int shift);
#endif