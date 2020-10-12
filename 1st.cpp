#include <iostream>
using namespace std;
int main () {
	int A, B, temp;
    A = 1;
    B = 2;

    /*cetak nilai A dan B sebelum pertukaran*/
    cout << "A = " << A <<endl;
    cout << "B = " << B <<endl;
	temp=A;
    A=B;
    B=temp;

    /*cetak nilai A dan B setelah pertukaran*/
    cout << "A = " << A <<endl;
    cout << "B = " << B <<endl;
 }
