#include<iostream>
#include<iomanip>
using namespace std;

string singkat (int asli);          //fungsi buat ubah 3 nol jadi tulisan "rb"

main () {
    int jumlah, harga;
    string daftar_kmr[] = {"Canon 600D", "Canon 70D", "Fujifilm X-T10", "Sony A6000", "Sony A7S"};
    string daftar_lns[] = {"Lensa Kit", "Lensa Fix", "Lensa Wide", "Lensa Makro", "Lensa Tele"};
    string daftar_alt[] = {"Memory Card", "Reflektor", "Tripod 1.5m", "Flash Eksternal", "Tas Kamera"};
    int harga_kmr[] = {80000, 130000, 175000, 230000, 350000};
    int harga_lns[] = {20000, 40000, 45000, 55000, 60000};
    int harga_alt[] = {5000, 8000, 10000, 17000, 20000};

    cout<<"Selamat datang di Rental Kamera Online"<<endl;
    cout<<"Silahkan pilih kamera serta peralatan yang ingin dirental\n";
    cout<<"\nDaftar Kamera:\tHarga:\t|\tDaftar Lensa:\tHarga:\t|\tDaftar Alat:\tHarga:\n";
    cout<<setfill('-')<<setw(90)<<'-'<<endl;    //buat ngasi garis pemisah antara header dan isi tabel

    for (int i = 0; i < 5; i++)     //buat nampilin barang rental pake perulangan
    {
        cout<<daftar_kmr[i]<<"\t"<<singkat(harga_kmr[i])<<"\t|\t"<<daftar_lns[i]<<"\t"<<singkat(harga_lns[i])<<"\t|\t"<<daftar_alt[i]<<"\t"<<singkat(harga_alt[i]);
        cout<<endl;
    }

    cout<<"\nNb:\t- Semua harga adalah harga rental per hari\n\t- Kamera hanya body nya saja\n";

    cout<<endl;
    system("pause");
}

string singkat (int asli) {
    int sisa = asli / 1000;         //buat ngilangin 3 nol
    return to_string(sisa) + "rb";  //to_string buat genti tipe int jadi string
}