#include <iostream>
#include <iomanip>
using namespace std;

int main () {
    int type, n, m, kali, pangkat;

    cout<<"Perkalian & Perpangkatan"<<setfill('=')<<setw(6)<<'='<<endl;
    cout<<"1. Perkalian\n"<<"2. Perpangkatan\n"<<"Pilih : ";
    cin>>type;

    if (type != 1 && type != 2) {
        cout<<"salah input!";
    } else {
        cout<<"Input angka N : ";
        cin>>n;
        cout<<"Input angka M : ";
        cin>>m;
        cout<<"Hasil ";
        
        switch (type) {
            case 1:
                cout<<n<<" x "<<m<<endl;

                for (int x = 1; x <= n; x++) {
                    kali += m;

                    if (x != n) {
                        cout<<m<<" + ";
                    } else {
                        cout<<m<<" = "<<kali;
                    }
                }
                break;
            case 2:
                cout<<n<<" ^ "<<m<<endl;
                pangkat = 1; 
                
                for (int x = 1; x <= m; x++) {
                    pangkat *= n;

                    if (x != m ) {
                        cout<<n<<" x ";
                    } else {
                        cout<<n<<" = "<<pangkat;
                    }
                }
                break;
        }
    }

    cout<<"\n\nTerima kasih :)\n\n";
    
    system("pause");
}