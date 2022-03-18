#include <iostream>
#include "tracereader.c"
#include <fstream>
#include <stdio.h>
#include <string>
#include "string.h"
#include <iomanip>
#include <cstring>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#define BADFLAG 1
using namespace std;

int main(int argc, char** argv){
    std::string line;
    int numlines = 0;
    int count = 0;
    int option;
    int addresses;
    char ptrArr[300]; //for dictionary
    char *c;
    p2AddrTr ptr;
    unsigned int vAddr;
    //std::ifstream trace(argv[1]);
    FILE* trace2 = fopen("trace.tr", "r");

  while ( (option = getopt(argc, argv, "n:o:")) != -1) { 
    switch (option) { 
    case 'n': /* Number of addresses to process */ 
      // optarg will contain the string following -n  
      // Process appropriately (e.g. convert to integer atoi(optarg))
      addresses = option;
      break; 
    case 'o': /* produce map of pages */ 
      // optarg contains the output method... 
      break; 
    default: 
      // print something about the usage and die... 
      exit(BADFLAG);  // BADFLAG is an error # defined in a header 
    } 
 }
  int idx = optind;
  while (argv[idx] != NULL) {
    cout << argv[idx] << endl;
    idx++;
  }
    while (!feof(trace2)){ // iterate over trace file 
        if(NextAddress(trace2, &ptr) && count <= addresses){
            vAddr = ptr.addr;
            cout << vAddr << endl;
            count++;
        }
    }
}

//next up implement getopt
//pull necessary bits determined by args

//you need main, split the pagetable operation for insert and search(can be in one file, if not maybe two), and tlb
//main datastructures: pageTable (multi paging level setup), node is "Level", 