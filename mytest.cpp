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

        }
        bool getAtTest(){

        }
        // tests for CSRList class
        bool assignmentOperatorTest(){

        }
        bool getAtTest(){

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

    return 0;
}