#ifndef LEVEL
#define LEVEL

#include <stdlib.h>
#include "map.h"
#include <math.h>

class pageTable;

class Level{
	public:
		Level();							//default constructor
		Level(int, pageTable*);				// this is an overloaded constructor
		Level **nextLevel					//
		Map* map;
		unsigned int depth;
		pageTable* pageTable;
		void nextLevel();
		void nullLevel();
		void mapPtr();
}