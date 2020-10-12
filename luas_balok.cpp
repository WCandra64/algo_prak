#include <iostream>
using namespace std;

int main () {
    int p, l, t;
    cout<<"Masukkan panjang, lebar, dan tinggi dari balok!\nPanjang (cm) : ";
    cin>>p;
    cout<<"Lebar (cm) : ";
    cin>>l;
    cout<<"Tinggi (cm) : ";
    cin>>t;
    cout<<"\nLuas permukaan dari balok ini adalah "<<2*(p*l+p*t+l*t)<<endl;
    cout<<"Volume dari balok ini adalah "<<p*l*t<<endl;

    return 0;
}