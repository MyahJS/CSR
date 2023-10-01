// CMSC 341 - Fall 2023 - Project 1
#include "csr.h"

class Tester{
    public:
        // tests for CSR class
        bool compressTest(){
            // define result flag
            // will be returned at end of all tests
            bool all_result = true;
            // Case 1: normal case
            // input array size matches number of rows and cols
            bool result = true;
            int matrix1[] = {
                1, 0, 0,
                0, 0, 2,
                0, 3, 0,
                0, 0, 0
            };
            CSR csrNormal;
            csrNormal.compress(4, 3, matrix1, 12);
            result = result && (csrNormal.m_m == 4);
            result = result && (csrNormal.m_n == 3);
            result = result && (csrNormal.m_nonzeros == 3);
            result = result && (csrNormal.m_values[0] == 1);
            result = result && (csrNormal.m_values[1] == 2);
            result = result && (csrNormal.m_values[2] == 3);
            result = result && (csrNormal.m_col_index[0] == 0);
            result = result && (csrNormal.m_col_index[1] == 2);
            result = result && (csrNormal.m_col_index[2] == 1);
            result = result && (csrNormal.m_row_index[0] == 0);
            result = result && (csrNormal.m_row_index[1] == 1);
            result = result && (csrNormal.m_row_index[2] == 2);
            result = result && (csrNormal.m_row_index[3] == 3);
            result = result && (csrNormal.m_row_index[4] == 3);
            cout << endl << "Compress normal case: ";
            if (result){
                cout << "PASS" << endl;
            } else {
                cout << "FAIL" << endl;
            }
            all_result = all_result && result;

            // Case 2: error case 1
            // input array is less than number of rows and cols
            result = true;
            int matrix2[] = {
                0, 1, 0, 
                0
            };
            CSR csrError1;
            csrError1.compress(4, 3, matrix2, 4);
            result = result && (csrError1.m_m == 4);
            result = result && (csrError1.m_n == 3);
            result = result && (csrError1.m_nonzeros == 1);
            result = result && (csrError1.m_values[0] == 1);
            result = result && (csrError1.m_col_index[0] == 1);
            result = result && (csrError1.m_row_index[0] == 0);
            result = result && (csrError1.m_row_index[1] == 1);
            result = result && (csrError1.m_row_index[2] == 1);
            result = result && (csrError1.m_row_index[3] == 1);
            result = result && (csrError1.m_row_index[4] == 1);
            cout << endl << "Compress first error case: ";
            if (result){
                cout << "PASS" << endl;
            } else {
                cout << "FAIL" << endl;
            }
            all_result = all_result && result;

            // Case 3: error case 2
            // m and n are 0 but input array is not empty
            result = true;
            int matrix3[] = {
                1, 2, 3,
                4, 5, 6
            };
            CSR csrError2;
            csrError2.compress(0, 0, matrix3, 6);
            result = result && (csrError2.m_m == 0);
            result = result && (csrError2.m_n == 0);
            result = result && (csrError2.m_nonzeros == 0);
            result = result && (csrError2.m_values == nullptr);
            result = result && (csrError2.m_col_index == nullptr);
            result = result && (csrError2.m_row_index == nullptr);
            cout << endl << "Compress second error case: ";
            if (result){
                cout << "PASS" << endl;
            } else {
                cout << "FAIL" << endl;
            }
            all_result = all_result && result;

            return all_result;
        }
        bool equalityOperatorTest(){
            bool all_result = true;
            // Case 1: normal case
            // when objects are equal and when objects are not equal
            bool result = true;
            CSR csr1;
            csr1.m_m = 3;
            csr1.m_n = 3;
            csr1.m_nonzeros = 3;
            csr1.m_values = new int[3]{1, 2, 3};
            csr1.m_col_index = new int[3]{0, 2, 1};
            csr1.m_row_index = new int[4]{0, 1, 2, 3};

            CSR csr2;   // object with different values than first
            csr2.m_m = 2;
            csr2.m_n = 2;
            csr2.m_nonzeros = 2;
            csr2.m_values = new int[2]{1, 2};
            csr2.m_col_index = new int[2]{0, 1};
            csr2.m_row_index = new int[3]{0, 1, 2};

            CSR csr3;   // object with same values as the first
            csr3.m_m = 3;
            csr3.m_n = 3;
            csr3.m_nonzeros = 3;
            csr3.m_values = new int[3]{1, 2, 3};
            csr3.m_col_index = new int[3]{0, 2, 1};
            csr3.m_row_index = new int[4]{0, 1, 2, 3};

            result = result && (!(csr1 == csr2));
            result = result && (csr1 == csr3);
            cout << endl << "Equality operator normal case: ";
            if (result){
                cout << "PASS" << endl;
            } else {
                cout << "FAIL" << endl;
            }
            all_result = all_result && result;

            // Case 2: edge case
            // both objects are empty
            result = true;
            CSR csr4;
            CSR csr5;
            result = result && (csr4 == csr5);
            cout << endl << "Equality operator edge case: ";
            if (result){
                cout << "PASS" << endl;
            } else {
                cout << "FAIL" << endl;
            }
            all_result = all_result && result;

            return all_result;

        }
        bool getAtTest(){
            bool all_result = true;
            // Case 1: edge case
            // make sure exception is thrown when row or col index is out of bounds
            bool result = true;
            CSR csr;
            csr.m_m = 3;
            csr.m_n = 3;
            csr.m_values = new int[3]{1, 2, 3};
            csr.m_col_index = new int[3]{0, 2, 1};
            csr.m_row_index = new int[4]{0, 1, 2, 3};
            try {
                // invalid row index
                csr.getAt(3, 1);
                result = false; // should skip this line if exception thrown
            } catch (const runtime_error& e){
                result = result && (string(e.what()) == "Row index out of bounds");
            }
            cout << endl << "GetAt function exception 1: ";
            if (result){
                cout << "PASS" << endl;
            } else {
                cout << "FAIL" << endl;
            }
            all_result = all_result && result;

            result = true;
            try {
                // invalid column index
                csr.getAt(1, 3);
                result = false; // should skip this line if exception thrown
            } catch (const runtime_error& e) {
                result = result && (string(e.what()) == "Column index out of bounds");
            }
            cout << endl << "GetAt function exception 2: ";
            if (result){
                cout << "PASS" << endl;
            } else {
                cout << "FAIL" << endl;
            }
            all_result = all_result && result;

            return all_result;
        }
        // tests for CSRList class
        bool assignmentOperatorTest(){

        }
        bool listGetAtTest(){

        }
    private:
    // for possible helpers
};

int main() {
    Tester test;

    if (test.compressTest()){
        cout << endl << "Compress function passed for all cases!" << endl;
    } else {
        cout << endl << "Compress function did not pass for all cases!" << endl;
    }
    if (test.equalityOperatorTest()){
        cout << endl << "Equality operator passed for all cases!" << endl;
    } else {
        cout << endl << "Equality operator did not pass for all cases!" << endl;
    }
    if (test.getAtTest()){
        cout << endl << "GetAt function passed for all cases!" << endl;
    } else {
        cout << endl << "GetAt function did not pass for all cases!" << endl;
    }

    return 0;
}