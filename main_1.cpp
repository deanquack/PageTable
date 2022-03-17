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
//#include <unistd.h>
using namespace std;

main(int argc, char** argv){
    std::string line;

    const char *delimiters = "\n\r !\"#$%&()*+,-./0123456789:;<=>?@[\\]^_`{|}~"; //this is needed for parsing the testfile
    int numlines = 0;
    
    char ptrArr[300]; //for dictionary
    char *c;
    p2AddrTr ptr;
    unsigned int vAddr;
    std::ifstream trace(argv[1]);
    FILE* trace2 = fopen(argv[1], "r");
    //this is for tokenizing and add the entire dictionary line by line
    char *word = strtok(ptrArr, delimiters);
    while (!feof(trace2)){ // iterate over trace file 
        //while(NextAddress(trace2, &ptr) != 0){
            if(NextAddress(trace2, &ptr)){
                vAddr = ptr.addr;
                cout << vAddr << endl;
            }
        //}
    }
}

//next up implement getopt
//pull necessary bits determined by args