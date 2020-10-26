#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main () {
    string uname, pwd, matkul;
    int input;
    float nilai, uh, uts, uas;

    cout<<"Login Akun "<<setfill('=')<<setw(10)<<'='<<endl;
    cout<<"Username\t: ";
    cin>>uname;
    cout<<"Password\t: ";
    cin>>pwd;
    cout <<setfill('=')<<setw(21)<<'='<<endl;

    if (uname == "admin") {
        if (pwd == "123") {
            cout<<"Login berhasil!\n"<<"\nInput Nilai Mata Kuliah\n"<<"1. Algoritma dan Pemrograman\n"<<"2. Kalkulus\n"<<"Pilih : ";
            cin>>input;

            switch (input) {
                case 1:
                    matkul = "Algoritma dan Pemrograman";
                    break;
                case 2:
                    matkul = "Kalkulus";
                    break;
                default:
                    matkul = "Input anda salah!";
            }

            if (input == 1 || input == 2) {
                cout<<"Nilai Harian\t: ";
                cin>>uh;
                cout<<"Nilai UTS\t: ";
                cin>>uts;
                cout<<"Nilai UAS\t: ";
                cin>>uas;

                nilai = (uh + uts + uas) / 3;

                if (nilai >= 80) {
                    cout<<"\nAnda lulus "<<matkul<<" dengan nilai "<<setprecision(6)<<nilai;
                } else {
                    cout<<"\nAnda tidak lulus "<<matkul<<" dengan nilai "<<setprecision(6)<<nilai;
                }
            } else {
                cout<<endl<<matkul;
            }
        } else {
            cout<<"\nPassword anda salah!";
        }
    } else {
        if (pwd == "123") {
            cout<<"\nUsername anda salah!";
        } else {
            cout<<"\nUsername dan Password anda salah!";
        }
    }

    cout<<endl;
    
    system("pause");
}