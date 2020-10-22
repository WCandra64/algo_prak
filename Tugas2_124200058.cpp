#include <iostream>
using namespace std;

int main () {
    int uayah, bayah, uibu, bibu, uanak1, banak1, uanak2, banak2, biaya;

    cout<<"Umur Ayah\t: ";
    cin>>uayah;
    cout<<"Umur Ibu\t: ";
    cin>>uibu;
    cout<<"Umur Anak 1\t: ";
    cin>>uanak1;
    cout<<"Umur Anak 2\t: ";
    cin>>uanak2;

    bayah = (uayah<=12) ? 15000 : (uayah<=20&&uayah>12) ? 20000 : 30000;
    bibu = (uibu<=12) ? 15000 : (uibu<=20&&uibu>12) ? 20000 : 30000;
    banak1 = (uanak1<=12) ? 15000 : (uanak1<=20&&uanak1>12) ? 20000 : 30000;
    banak2 = (uanak2<=12) ? 15000 : (uanak2<=20&&uanak2>12) ? 20000 : 30000;

    biaya = (bayah*30)+(bibu*30)+(banak1*30)+(banak2*30);

    printf("Tagihan satu bulan adalah Rp.%d\n", biaya);

    system("pause");
}