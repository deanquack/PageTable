#ifndef PAGETABLE_H
#define PAGETABLE_H

#define CACHE_TLB 0

#include <stdlib.h>

typedef struct pageTable{ 
    unsigned int depth = 0;
    int *levelCount; 
    int bitShift[levelCount];
    int bitMask[];
    int entryCount[];
};

typedef struct Level{
    Level* nextLevel[];
    int map[];
};


void pageInsert(pageTable *pagetable, unsigned int virtualAddress, unsigned int frame);
Map* pageLookup(pageTable *pagetable, unsigned int virtualAddress);
unsigned int virtualAddressToPageNum (unsigned int virtualAddress, unsigned int mask, unsigned int shift); 









#endif