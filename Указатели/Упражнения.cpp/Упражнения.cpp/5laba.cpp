#include <iostream>
using namespace std;

// Function to add elements of two arrays and store the result in the third array
void addArrays(const float* arr1, const float* arr2, float* result, int size) {
    for (int i = 0; i < size; i++) {
        *(result + i) = *(arr1 + i) + *(arr2 + i);
    }
}

int main() {
    const int SIZE = 5;
    float array1[SIZE] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    float array2[SIZE] = { 5.5, 4.4, 3.3, 2.2, 1.1 };
    float result[SIZE];

    // Call function to add arrays
    addArrays(array1, array2, result, SIZE);

    // Display result
    cout << "Resulting array: ";
    for (int i = 0; i < SIZE; i++) {
        cout << *(result + i) << " ";
    }
    cout << endl;

    return 0;
}
