#ifndef PAGETABLE_H
#define PAGETABLE_H

#include <stdlib.h>

typedef struct pageTable{ 
    unsigned int levelCount;  
    unsigned int bitShift[levelCount];
    unsigned int bitMask[levelCount];
    unsigned int entryCount[levelCount];
};

typedef struct map{
    unsigned int nextLevel[levelCount];
    map map[];
};

pageTable pageInsert(pageTablePtr, address, frame);







#endif