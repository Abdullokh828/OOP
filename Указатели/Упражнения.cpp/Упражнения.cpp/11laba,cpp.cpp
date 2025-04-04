#include <iostream>
using namespace std;

const int CHUNK_SIZE = 10;     // size of one sub-array
const int NUM_CHUNKS = 10;     // number of sub-arrays
const int TOTAL_SIZE = CHUNK_SIZE * NUM_CHUNKS; // total number of elements

class VirtualArray {
private:
    int* chunks[NUM_CHUNKS]; // array of pointers to arrays of 10 elements each

public:
    VirtualArray() {
        for (int i = 0; i < NUM_CHUNKS; i++) {
            chunks[i] = new int[CHUNK_SIZE]; // allocate memory for each sub-array
        }
    }

    ~VirtualArray() {
        for (int i = 0; i < NUM_CHUNKS; i++) {
            delete[] chunks[i]; // free memory
        }
    }

    // Overload of the [] operator
    int& operator[](int index) {
        if (index < 0 || index >= TOTAL_SIZE) {
            cout << "Index out of bounds!" << endl;
            exit(1);
        }
        int chunkIndex = index / CHUNK_SIZE;   // determine which sub-array the element is in
        int innerIndex = index % CHUNK_SIZE;   // determine the position within the sub-array
        return *(*(chunks + chunkIndex) + innerIndex); // access the element via pointers
    }
};

int main() {
    VirtualArray a;

    // Filling the array
    for (int i = 0; i < TOTAL_SIZE; i++) {
        a[i] = i * 10; // fill with values 0, 10, 20, ...
    }

    // Displaying the array
    for (int i = 0; i < TOTAL_SIZE; i++) {
        cout << a[i] << " ";
        if ((i + 1) % CHUNK_SIZE == 0) cout << endl;
    }

    return 0;
}
