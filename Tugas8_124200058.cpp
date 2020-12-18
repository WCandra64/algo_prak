#include<iostream>
#include<iomanip>
#define phi 3.14159265
using namespace std;

int tipe;
float luas(float r), keliling(float r), volume(float r, float t);
void menu(), balik();

main () {
    char ulang;

    menu();

    system("pause");
}

void menu() {
    float jari, tinggi;

    cout<<"Hitung Luas Lingkaran "<<setfill('=')<<setw(10)<<'='<<endl;
    cout<<"1. Luas Lingkaran\n2. Keliling Lingkaran\n3. Volume Tabung\nPilih : ";
    cin>>tipe;

    switch(tipe) {
        case 1:
            cout<<"Jari-jari\t: ";
            cin>>jari;
            cout<<"Luas lingkaran adalah "<<luas(jari);
            break;
        case 2:
            cout<<"Jari-jari\t: ";
            cin>>jari;
            cout<<"Keliling lingkaran adalah "<<keliling(jari);
            break;
        case 3:
            cout<<"Jari-jari\t: ";
            cin>>jari;
            cout<<"Tinggi\t\t: ";
            cin>>tinggi;
            cout<<"Volume tabung adalah "<<volume(jari, tinggi);
            break;
        default:
            cout<<"Input Salah :)";
    }

    balik();
}

void balik() {
    char ulang;

    cout<<"\nUlangi program? (y/n) ";
    cin>>ulang;
    cout<<endl;

    switch(ulang){
        case 'y':
            menu();
            break;
        default:
            cout<<"Program selesai, Terima kasih :)"<<endl<<endl;
    }
}

float luas(float r) {
    return phi*r*r;
}

float keliling(float r) {
    return 2*phi*r;
}

float volume(float r, float t) {
    return luas(r)*t;
}