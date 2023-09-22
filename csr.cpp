// CMSC 341 - Fall 2023 - Project 1
#include "csr.h"
///////////////CSR Class Implementation///////////////
CSR::CSR(){
    // Default contructor
    // preconditions: none
    // postconditions: assign variables default values to hold before initialization

    m_values = nullptr;
    m_col_index = nullptr;
    m_row_index = nullptr;
    m_nonzeros = 0;
    m_m = 0;
    m_n = 0;
    m_next = nullptr;
}
CSR::~CSR(){
    // Destructor
    // precondtions: object is not empty
    // postconditions: deallocate all dynamically allocated memory

    if (m_values != nullptr){   //check if object is not empty
        delete[] m_values;
        delete[] m_col_index;
        delete[] m_row_index;
    } 
}
CSR::CSR(const CSR & rhs){
    // Copy constructor
    // precondtions: rhs is an existing object
    // postcondtions: create an identical object and return it

    if (rhs.m_values != nullptr){
        for (int i=0; i<rhs.m_nonzeros; i++){
            m_values[i] = rhs.m_values[i];
        }
        for (int i=0; i<rhs.m_nonzeros; i++){
            m_col_index[i] = rhs.m_col_index[i];
        }
        for (int i=0; i<(m_m+1); i++){
            m_row_index[i] = rhs.m_row_index[i];
        }
    } else {
        m_values = rhs.m_values;
        m_col_index = rhs.m_col_index;
        m_row_index = rhs.m_row_index;
    }
    m_nonzeros = rhs.m_nonzeros;
    m_m = rhs.m_m;
    m_n = rhs.m_n;
    m_next = rhs.m_next;
}
void CSR::clear(){
    // Clear
    // preconditions: object is not empty
    // postconditions: deallocate memory and create an empty object

    if (m_values != nullptr){
        delete[] m_values;
        delete[] m_col_index;
        delete[] m_row_index;
        m_values = nullptr;
        m_col_index = nullptr;
        m_row_index = nullptr;
        m_nonzeros = 0;
        m_m = 0;
        m_n = 0;
        m_next = nullptr;
    } 
}
bool CSR::empty() const{
    // Empty
    // precondtions: object exists
    // postconditions: return true if object is empty, else return false

    if (m_values==nullptr){
        return true;
    }
    return false;
}
void CSR::compress(int m, int n, int array[], int arraySize){
    // Compress
    // preconditions: object exists
    // postconditions: 
    
}
int CSR::getAt(int row, int  col) const{
    
} 
bool CSR::operator==(const CSR & rhs) const{
    
}
int CSR::sparseRatio(){
    
}
void CSR::dump(){
    cout << endl;
    if (!empty()){
        for (int i=0;i<m_nonzeros;i++)
            cout << m_values[i] << " ";
        cout << endl;
        for (int i=0;i<m_nonzeros;i++)
            cout << m_col_index[i] << " ";
        cout << endl;
        for (int i=0;i<m_m+1;i++)
            cout << m_row_index[i] << " ";
    }
    else
        cout << "The object is empty!";
    cout << endl;
}

//////////////CSRList Class Implementation///////////////
CSRList::CSRList(){
    
}
CSRList::CSRList(const CSRList & rhs){
    
}
CSRList::~CSRList(){
    
}
bool CSRList::empty() const{
    
}
void CSRList::insertAtHead(const CSR & matrix){
    
}
void CSRList::clear(){
    
}

int CSRList::getAt(int CSRIndex, int row, int col) const{
    
}
bool CSRList::operator== (const CSRList & rhs) const{
    
}
const CSRList& CSRList::operator=(const CSRList & rhs){
    
}
int CSRList::averageSparseRatio(){
    
}
void CSRList::dump(){
    if (!empty()){
        CSR* temp = m_head;
        while (temp != nullptr){
            temp->dump();
            temp = temp->m_next;
        }
    }
    else
        cout << "Error: List is empty!" << endl;
}