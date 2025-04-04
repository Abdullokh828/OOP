#include <iostream>
using namespace std;

// Custom string comparison function
int compstr(const char* s1, const char* s2) {
    while (*s1 && *s2) {
        if (*s1 < *s2) return -1;
        if (*s1 > *s2) return 1;
        ++s1;
        ++s2;
    }
    if (*s1 == *s2) return 0;
    return (*s1 < *s2) ? -1 : 1;
}

int main() {
    const char* str1 = "apple";
    const char* str2 = "banana";
    const char* str3 = "apple";
    const char* str4 = "apples";

    cout << "Comparing 'apple' and 'banana': " << compstr(str1, str2) << endl;  // -1
    cout << "Comparing 'apple' and 'apple' : " << compstr(str1, str3) << endl;  // 0
    cout << "Comparing 'apple' and 'apples': " << compstr(str1, str4) << endl;  // -1
    cout << "Comparing 'banana' and 'apple': " << compstr(str2, str1) << endl;  // 1

    return 0;
}
