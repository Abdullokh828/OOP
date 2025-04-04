#include <iostream>
#include <cstring>

using namespace std;

// Function to swap two pointers
void order(const char** p1, const char** p2) {
    if (strcmp(*p1, *p2) > 0) {
        const char* temp = *p1;
        *p1 = *p2;
        *p2 = temp;
    }
}

// Bubble sort function
void bsort(const char* arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            order(&arr[j], &arr[j + 1]);
        }
    }
}

int main() {
    

    // Array of pointers to strings
    const char* days[] = { "Monday", "Tuesday", "Wednesday", "Thursday",
                           "Friday", "Saturday", "Sunday" };
    int n = sizeof(days) / sizeof(days[0]);

    // Sorting the array
    bsort(days, n);

    // Display sorted days of the week
    cout << "Sorted days of the week:" << endl;
    for (int i = 0; i < n; i++) {
        cout << days[i] << endl;
    }

    return 0;
}
