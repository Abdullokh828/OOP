#include <iostream>
using namespace std; 
 

int main() {
	const int size = 10; 
	const int total = 100;


	int a0[size], a1[size], a2[size], a3[size], a4[size];
	int a5[size], a6[size], a7[size], a8[size], a9[size];


	int* ap[size] = { a0, a1, a2, a3, a4, a5, a6, a7, a8, a9 };
	

	for (int i = 0; i < size; i++) {

		for (int j = 0; j < size; j++) {

			ap[i][j] = (i * size + j) * 10;

		}

	}

	cout << "values in the fragmented arrays : " << endl;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << ap[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
