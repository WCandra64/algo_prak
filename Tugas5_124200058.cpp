#include <iostream>
#include <iomanip>
using namespace std;

int main () {
    int type, p, q, x, y;

    cout<<"Gambar Bangun Datar "<<setfill('=')<<setw(11)<<'='<<endl;
    cout<<"1. Kotak Bolong\n"<<"2. Segitiga\n"<<"Pilih : ";
    cin>>type;
    cout<<endl;

    switch (type) {
        case 1:
            cout<<"Panjang\t: ";
            cin>>y;
            cout<<"Lebar\t: ";
            cin>>x;

            for (p = 1; p <= y; p++) {
                for (q = 1; q <= x; q++) {
                    if (p == 1 || p == y) {
                        cout<<"* ";
                    } else {
                        if (q == 1 || q == x) {
                            cout<<"* ";
                        } else {
                            cout<<"  ";
                        }
                    }
                }
                cout<<endl;
            }
            break;
        case 2:
            cout<<"Tinggi\t: ";
            cin>>y;

            for (p = 1; p <= y; p++) {
                x=1;
                cout<<p;
                for (q = 1; q < p; q++) {
                    cout<<" "<<p+(y*q)-x;
                    x=x+q+1;
                }
                cout<<endl;
            }
            break;
        default:
            cout<<"Input anda salah!"<<endl;
    }
    
    cout<<endl;
    system("pause");
}