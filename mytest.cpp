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
    CSR testCopy(testFull);
    testCopy.dump();
    cout << (testFull==testCopy) << endl;
    cout << (testEmpty==testCopy) << endl;
    CSR testEmptyCopy(testEmpty);
    testEmptyCopy.dump();
    int array2[] = {0,0,0,0,100,200,0,0,300};
    CSR testGetAt;
    testGetAt.compress(3,3,array2,9);
    testGetAt.dump();
    cout << testGetAt.getAt(2,2) << endl;
    cout << testEmpty.sparseRatio() << endl;
    cout << testFull.sparseRatio() << endl;
    cout << testGetAt.sparseRatio() << endl;

    CSR aCSR;
    aCSR.compress(4,6,array1,24);
    CSR bCSR(aCSR);
    CSR cCSR;
    cCSR.compress(3,3,array2,9);
    CSR dCSR(cCSR);
    CSRList aCSRList;
    aCSRList.insertAtHead(aCSR);
    aCSRList.insertAtHead(cCSR);
    CSRList bCSRList;
    bCSRList.insertAtHead(dCSR);
    bCSRList.insertAtHead(bCSR);
    cout << endl << "Dumping aCSRList:" << endl;
    aCSRList.dump();
    cout << endl << "Dumping bCSRList:" << endl;
    bCSRList.dump();
    try{
        cout << endl << aCSRList.getAt(1,2,4) << endl;
    }
    catch (exception &e){
        cout << e.what() << endl;
    }

    return 0;
}