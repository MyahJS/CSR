// CMSC 341 - Fall 2023 - Project 1
#include "csr.h"

class Tester{
    
};

int main() {
    CSR testEmpty;
    testEmpty.dump();
    int array1[] = {10,20,0,0,0,0,0,30,0,40,0,0,0,0,50,60,70,0,0,0,0,0,0,80};
    CSR testFull;
    testFull.compress(4,6,array1,24);
    testFull.dump();

    return 0;
}