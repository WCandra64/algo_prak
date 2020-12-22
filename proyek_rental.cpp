#include<iostream>
#include<iomanip>
using namespace std;

string singkat (int asli);          //fungsi buat ubah 3 nol jadi tulisan "rb"
void input (), ulang (), harga (), salah ();          //fungsi buat ubah 3 nol jadi tulisan "rb"
int masukan[0][4], urutan = 1;

string daftar_kmr[] = {"Canon 600D", "Canon 70D", "Fujifilm T10", "Sony A6000", "Sony A7S"};
string daftar_lns[] = {"Lensa Kit", "Lensa Fix", "Lensa Wide", "Lensa Makro", "Lensa Tele"};
string daftar_alt[] = {"Memory Card", "Reflektor", "Tripod 1.5m", "Flash ", "Tas Kamera"};
int harga_kmr[] = {80000, 130000, 175000, 230000, 350000};
int harga_lns[] = {20000, 40000, 45000, 55000, 60000};
int harga_alt[] = {5000, 8000, 10000, 17000, 20000};

main () {
    int total = 0;

    cout<<"Selamat datang di Rental Kamera Online"<<endl;
    cout<<"Silahkan pilih kamera serta peralatan yang ingin dirental\n";
    cout<<"\nDaftar Kamera:\tHarga:\t| Daftar Lensa:\tHarga:\t| Daftar Alat:\tHarga:\n";
    cout<<setfill('-')<<setw(90)<<'-'<<endl;    //buat ngasi garis pemisah antara header dan isi tabel

    for (int i = 0; i < 5; i++)     //buat nampilin barang rental pake perulangan
    {
        cout<<i+1<<" "<<daftar_kmr[i]<<"\t"<<singkat(harga_kmr[i])<<"\t| "<<i+1<<" "<<daftar_lns[i]<<"\t"<<singkat(harga_lns[i])<<"\t| "<<i+1<<" "<<daftar_alt[i]<<"\t"<<singkat(harga_alt[i]);
        cout<<endl;
    }

    cout<<"\nNb:\n- Semua harga adalah harga rental per hari\n- Kamera hanya body nya saja\n- Kamera = kategori 1, Lensa = kategori 2, Alat = kategori 3\n";

    input();

    cout<<"\nDaftar Harga\t:\n";
    for (int i = 0; i < urutan; i++)
    {
        switch (masukan[i][0])
        {
            case 1:
                total += harga_kmr[masukan[i][1]-1] * masukan[i][2] * masukan[i][3];
                cout<<i+1<<". "<<daftar_kmr[masukan[i][1]-1]<<" ("<<masukan[i][2]<<")\t: "<<singkat(harga_kmr[masukan[i][1]-1] * masukan[i][2] * masukan[i][3]);
                break;
            case 2:
                total += harga_lns[masukan[i][1]-1] * masukan[i][2] * masukan[i][3];
                cout<<i+1<<". "<<daftar_lns[masukan[i][1]-1]<<" ("<<masukan[i][2]<<")\t: "<<singkat(harga_lns[masukan[i][1]-1] * masukan[i][2] * masukan[i][3]);
                break;
            case 3:
                total += harga_alt[masukan[i][1]-1] * masukan[i][2] * masukan[i][3];
                cout<<i+1<<". "<<daftar_alt[masukan[i][1]-1]<<" ("<<masukan[i][2]<<")\t: "<<singkat(harga_alt[masukan[i][1]-1] * masukan[i][2] * masukan[i][3]);
                break;
            default:
                break;
        }
        cout<<endl;
    }
    cout<<"\nTotal Harga\t: "<<singkat(total)<<endl;

    cout<<"\nTerima kasih telah merental di toko online kami! :D\n\n";
    system("pause");
}

string singkat (int asli) {
    int sisa = asli / 1000;         //buat ngilangin 3 nol
    return to_string(sisa) + "rb";  //to_string buat genti tipe int jadi string
}

void input () {
    cout<<"\nBarang ke-"<<urutan<<" : ";
    cout<<"\nMasukkan kategori barang yang akan dirental\t: ";
    cin>>masukan[urutan-1][0];
    if (masukan[urutan-1][0] <= 3 && masukan[urutan-1][0] > 0) {
        cout<<"Masukkan nomor barang yang akan dirental\t: ";
        cin>>masukan[urutan-1][1];
        if (masukan[urutan-1][1] <= 5 && masukan[urutan-1][0] > 0) {
            cout<<"Jumlah barang yang ingin dirental\t\t: ";
            cin>>masukan[urutan-1][2];
            cout<<"Lama waktu/hari perentalan\t\t\t: ";
            cin>>masukan[urutan-1][3];
        } else {
            salah ();
        }
    } else {
        salah ();
    }

    ulang();
}

void ulang () {
    char ulang;

    cout<<"Tambah Barang? (y/n) ";
    cin>>ulang;

    switch(ulang){
        case 'y':
            urutan += 1;
            input();
            break;
        default:
            break;
    }
}

void salah () {
    cout<<"Maaf, input anda salah, mohon ulangi program!\n"; 
    system("pause");
    exit(0);
}