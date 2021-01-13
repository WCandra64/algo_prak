#include<iostream>
#include<iomanip>
using namespace std;

void login (), menu (), tambah (), lihat (), cari (), update (int index);
string* makanan,** nm_bahan;
int banyak,* byk_bahan,** jml_bahan,** hrg_bahan;

main () {
    login ();
    menu ();
}

void login () {
    string uname = "admin", pwd = "admin123", iuname, ipwd;

    cout<<"Login Admin\nUsername\t: ";
    cin>>iuname;
    cout<<"Password\t: ";
    cin>>ipwd;

    if (iuname == uname) {
        if (ipwd == pwd) {
            cout<<"Login sukses\n\n\n\n\n\n";
        system ("pause");
        system ("cls");
        } else {
            cout<<"Password salah\n\n";
            login ();
        }
    } else {
        if (ipwd == pwd) {
            cout<<"Username salah\n\n";
            login ();
        } else {
            cout<<"Username dan Password salah\n\n";
            login ();
        }
    }
}

void menu () {
    int pilihan;

    cout<<"Menu\n1. Tambah Makanan\n2. Lihat Makanan\n3. Cari Makanan\n4. Logout\nPilih : ";
    cin>>pilihan;

    switch (pilihan) {
        case 1:
            tambah ();
            break;
        case 2:
            lihat ();
            break;
        case 3:
            cari ();
            break;
        case 4:
            system ("cls");
            main ();
            break;
        default:
            cout<<"Salah Input\n\n\n";
            system ("pause");
            system ("cls");
            menu ();
            break;
    }
}

void tambah () {
    int base = 0, banyak2, i, *kolom;

    cout<<"Masukkan banyak makanan\t: ";
    if (banyak == 0) {
        i = 0;
        cin>>banyak;
    } else {
        base = banyak;
        i = base;
        cin>>banyak2;
        banyak += banyak2;
    }
    string makananLokal[banyak],* nm_bahanLokal[banyak];
    int byk_bahanLokal[banyak],* jml_bahanLokal[banyak],* hrg_bahanLokal[banyak];
    for (int j = 0; j < base; j++) {
        makananLokal[j] = makanan[j];
        byk_bahanLokal[j] = byk_bahan[j];
        nm_bahanLokal[j] = nm_bahan[j];
        jml_bahanLokal[j] = jml_bahan[j];
        hrg_bahanLokal[j] = hrg_bahan[j];
    }

    for (i; i < banyak; i++) {
        cout<<"Masukkan data makanan ke-"<<i+1<<"\nNama\t: ";
        cin.ignore();
        getline(cin, makananLokal[i]);
        cout<<"Banyak Bahan\t: ";
        cin>>byk_bahanLokal[i];
        nm_bahanLokal[i] = new string [byk_bahanLokal[i]];
        jml_bahanLokal[i] = new int [byk_bahanLokal[i]];
        hrg_bahanLokal[i] = new int [byk_bahanLokal[i]];

        for(int j = 0; j < byk_bahanLokal[i]; j++) {
            cout<<"\tBahan "<<j+1<<"\n\tNama\t: ";
            cin.ignore();
            getline(cin, nm_bahanLokal[i][j]);
            cout<<"\tJumlah\t: ";
            cin>>jml_bahanLokal[i][j];
            cout<<"\tHarga\t: ";
            cin>>hrg_bahanLokal[i][j];
        }

        cout<<endl;
    }

    makanan = makananLokal;
    byk_bahan = byk_bahanLokal;
    nm_bahan = nm_bahanLokal;
    jml_bahan = jml_bahanLokal;
    hrg_bahan = hrg_bahanLokal;

    cout<<"\n\nBerhasil memasukkan data makanan\n\n\n";
    system("pause");
    system("cls");
    menu ();
}

void lihat () {
    cout<<"Jumlah makanan\t: "<<banyak;
    
    for (int i = 0; i < banyak; i++) {
        int total = 0;

        cout<<"\nData makanan ke-"<<i+1<<endl;
        cout<<"Nama\t: "<<makanan[i]<<endl;

        for(int j = 0; j < byk_bahan[i]; j++) {
            int harga = 0;

            cout<<"\tBahan "<<j+1<<"\n\tNama\t: ";
            cout<<nm_bahan[i][j];
            cout<<"\n\tHarga\t: ";
            harga = hrg_bahan[i][j] * jml_bahan[i][j];
            cout<<harga;
            total += harga;
            cout<<endl;
        }
        cout<<"Total Harga : "<<total<<endl;
    }
    
    cout<<endl<<endl;
    system("pause");
    system("cls");
    menu ();
}

void cari () {
    int i = 0, ditemukan = 0;
    char perbaru;
    string pencarian;
    cout<<"Cari nama makanan\t: ";
    cin.ignore();
    getline(cin,pencarian);
    
    do {
        int total = 0;

        if (pencarian == makanan[i]) {
            cout<<"Data ditemukan\n";
            cout<<"Data makanan ke-"<<i+1<<endl;
            cout<<"Nama\t: "<<makanan[i]<<endl;

            for(int j = 0; j < byk_bahan[i]; j++) {
                int harga = 0;

                cout<<"\tBahan "<<j+1<<"\n\tNama\t: ";
                cout<<nm_bahan[i][j];
                cout<<"\n\tHarga\t: ";
                harga = hrg_bahan[i][j] * jml_bahan[i][j];
                cout<<harga;
                total += harga;
                cout<<endl;
            }
            cout<<"Total Harga : "<<total<<endl;
            cout<<"\nUpdate data (y/n) ? ";
            cin>>perbaru;
            switch (perbaru) {
                case 'y':
                    update (i);
                    break;
                default:
                    break;
            }
            ditemukan++;
        }
        
        i++;
    }
    while (i < banyak);

    if (ditemukan != 1) cout<<"Data tidak ditemukan\n\n\n";
    
    system("pause");
    system("cls");
    menu ();
}

void update (int index) {
    cout<<"Masukkan data makanan ke-"<<index+1<<"\nNama\t: ";
    cin.ignore();
    getline(cin, makanan[index]);

    for(int j = 0; j < byk_bahan[index]; j++) {
        cout<<"\tBahan "<<j+1<<"\n\tNama\t: ";
        getline(cin, nm_bahan[index][j]);
        cout<<"\tJumlah\t: ";
        cin>>jml_bahan[index][j];
        cout<<"\tHarga\t: ";
        cin>>hrg_bahan[index][j];
    }

    cout<<endl<<"Update berhasil\n\n\n";
}