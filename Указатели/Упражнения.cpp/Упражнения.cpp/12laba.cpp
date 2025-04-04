#include <iostream>
using namespace std;

const int MEM_SIZE = 100;
float fmemory[MEM_SIZE]; // simulated float memory
int pmemory[MEM_SIZE];   // simulated pointer memory
int fmem_top = 0;        // top of float memory
int pmem_top = 0;        // top of pointer memory

class Float {
private:
    int addr; // index in fmemory

public:
    Float(float val) {
        if (fmem_top < MEM_SIZE) {
            addr = fmem_top;
            fmemory[fmem_top++] = val;
        }
        else {
            cerr << "Float memory overflow" << endl;
            exit(1);
        }
    }

    // Address-of operator returns index in fmemory
    int operator&() const {
        return addr;
    }
};

class ptrFloat {
private:
    int addr; // index in pmemory

public:
    ptrFloat(int float_addr) {
        if (pmem_top < MEM_SIZE) {
            addr = pmem_top;
            pmemory[pmem_top++] = float_addr;
        }
        else {
            cerr << "Pointer memory overflow" << endl;
            exit(1);
        }
    }

    // Dereference operator returns reference to value in fmemory
    float& operator*() {
        return fmemory[pmemory[addr]];
    }
};

int main() {
    Float var1 = 1.234f;
    Float var2 = 5.678f;

    ptrFloat ptr1 = &var1;
    ptrFloat ptr2 = &var2;

    cout << "*ptr1 = " << *ptr1 << endl;
    cout << "*ptr2 = " << *ptr2 << endl;

    *ptr1 = 7.123f;
    *ptr2 = 8.456f;

    cout << "*ptr1 = " << *ptr1 << endl;
    cout << "*ptr2 = " << *ptr2 << endl;

    return 0;
}
