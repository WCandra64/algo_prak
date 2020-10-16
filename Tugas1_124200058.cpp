#include <iostream>
using namespace std;

int main () {
    char nama[36], nim[12];
    int uts, uas, avg;

    cout<<"Nama\t: ";
    cin>>nama;
    cout<<"NIM\t: ";
    cin>>nim;
    cout<<"UTS\t: ";
    cin>>uts;
    cout<<"UAS\t: ";
    cin>>uas;

    avg = (uts+uas)/2;

    printf("\nHai, nama saya %s, nim %s \nNilai akhir saya %d\n\n", nama, nim, avg);

    system("pause");
}