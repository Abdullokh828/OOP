#include <iostream>
#include <cstring>
using namespace std;

class Person {
private:
    char name[40];
    float salary;

public:
    void setData() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter salary: ";
        cin >> salary;
    }

    void printData() const {
        cout << "Name: " << name << ", Salary: " << salary << endl;
    }

    float getSalary() const {
        return salary;
    }
};

void salsort(Person** pp, int n) {
    for (int j = 0; j < n - 1; j++) {
        for (int k = j + 1; k < n; k++) {
            if ((*(pp + j))->getSalary() > (*(pp + k))->getSalary()) {
                Person* temp = *(pp + j);
                *(pp + j) = *(pp + k);
                *(pp + k) = temp;
            }
        }
    }
}

int main() {
    const int SIZE = 3;
    Person* persPtr[SIZE];

    for (int i = 0; i < SIZE; i++) {
        persPtr[i] = new Person;
        persPtr[i]->setData();
    }

    salsort(persPtr, SIZE);

    cout << "\nSorted by salary:\n";
    for (int i = 0; i < SIZE; i++) {
        persPtr[i]->printData();
    }

    for (int i = 0; i < SIZE; i++) {
        delete persPtr[i];
    }

    return 0;
}
