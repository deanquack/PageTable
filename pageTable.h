#ifndef PAGETABLE_H
#define PAGETABLE_H

#include <stdlib.h>
typedef struct pageTable{ 
    unsigned int levelCount;  
    unsigned int bitmask[levelCount];
    unsigned int bitShift;
    unsigned int entryCount;
};

typedef struct level{
    pageTable *pageTablePtr;
    unsigned int depth;
    level *nextLevelPtr[levelCount];

    unsigned int map[];
};

pageTable pageInsert(pageTablePtr, address, frame);







#endif