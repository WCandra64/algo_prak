#include<iostream>
#include<iomanip>
using namespace std;

void input (int *urutan), ulang (), salah (), rincian (string brg[], int hrg[], int skg, int no, int jml, int hr, int *ttl), pemisah (int asli);
int masukan[0][4], pangkat (int batas);

int main () {
    string daftar_kmr[] = {"Canon 600D", "Nikon D90", "Gopro 4", "Sony A6000", "Sony A7S"};
    string daftar_lns[] = {"Lensa Kit", "Lensa Fix", "Lensa Wide", "Lensa Makro", "Lensa Tele"};
    string daftar_alt[] = {"Memory Card", "Reflektor", "Tripod 1.5m", "Flash ", "Tas Kamera"};
    string nama, alamat, id;
    int harga_kmr[] = {80000, 140000, 190000, 230000, 350000};
    int harga_lns[] = {20000, 40000, 45000, 55000, 60000};
    int harga_alt[] = {5000, 8000, 10000, 17000, 20000};
    int urutan = 1, total = 0;

    cout<<setfill('-')<<setw(73)<<'-'<<endl;
    cout<<"\t\tSelamat datang di Rental Kamera Online"<<endl;
    cout<<setfill('-')<<setw(73)<<'-'<<endl<<endl;
    cout<<"Masukkan Nama Anda\t\t: ";
    getline(cin, nama);
    cout<<"Masukkan Alamat Anda\t\t: ";
    getline(cin, alamat);
    cout<<"Masukkan Nomor Kartu Id Anda\t: ";
    getline(cin, id);
    cout<<"\n\n\n\nIdentitas anda sudah tercatat.\n";
    system("pause");
    system("cls");

    cout<<"Silahkan pilih kamera serta peralatan yang ingin dirental\n";
    cout<<"\n Daftar Kamera:\tHarga:\t| Daftar Lensa:\tHarga:\t| Daftar Alat:\tHarga:\n";
    cout<<setfill('-')<<setw(73)<<'-'<<endl;
    
    for (int i = 0; i < 5; i++) {
        cout<<" "<<i+1<<" "<<daftar_kmr[i]<<"\t";
        pemisah(harga_kmr[i]);
        cout<<"\t| "<<i+1<<" "<<daftar_lns[i]<<"\t";
        pemisah(harga_lns[i]);
        cout<<"\t| "<<i+1<<" "<<daftar_alt[i]<<"\t";
        pemisah(harga_alt[i]);
        cout<<endl;
    }

    cout<<"\nNb:\n- Semua harga adalah harga rental per hari\n- Kamera hanya body nya saja\n- Kamera = kategori 1, Lensa = kategori 2, Alat = kategori 3\n";
    
    input(&urutan);
    cout<<"\n\nInput anda sudah tercatat.\n";
    system("pause");
    system("cls");

    cout<<setfill('-')<<setw(40)<<'-'<<endl;
    cout<<"\t\tRincian"<<endl;
    cout<<setfill('-')<<setw(40)<<'-'<<endl<<endl;
    cout<<"Nama Perental\t: "<<nama;
    cout<<"\n\nDaftar Barang yang Dirental\t:\n";
    for (int i = 0; i < urutan; i++) {
        int nomor = masukan[i][1] - 1, jumlah = masukan[i][2], hari = masukan[i][3];
        
        switch (masukan[i][0]) {
            case 1:
                rincian(daftar_kmr, harga_kmr, i, nomor, jumlah, hari, &total);
                break;
            case 2:
                rincian(daftar_lns, harga_lns, i, nomor, jumlah, hari, &total);
                break;
            case 3:
                rincian(daftar_alt, harga_alt, i, nomor, jumlah, hari, &total);
                break;
        }

        cout<<endl;
    }
    cout<<setfill('-')<<setw(40)<<'-'<<endl;
    cout<<"Total Harga\t: Rp";
    pemisah(total);
    cout<<endl;

    cout<<"\n\n\nTerima kasih telah merental di toko online kami! :D\n\n";
    system("pause");
}

void pemisah (int asli) {
    int digit = 0, dummy = asli;

    while (dummy != 0) {
        digit ++;
        dummy /= 10;
    }

    int terpisah[digit];

    for (int i = digit; i > 0; i--) {
        terpisah[i-1] = (asli / (pangkat(i))) % 10;
		if ((i % 3 == 0) && (i != digit))
            cout<<".";
		cout<<terpisah[i-1];
    }
}

int pangkat (int batas) {
	int pangkat = 1;
	for (int i = 1; i < batas; i++) {
        pangkat *= 10;
    }
	return pangkat;
}

void input (int *urutan) {
    cout<<"\nBarang ke-"<<*urutan<<" : \n";
    cout<<"Masukkan kategori barang yang akan dirental\t: ";
    cin>>masukan[*urutan-1][0];
    if (masukan[*urutan-1][0] <= 3 && masukan[*urutan-1][0] > 0) {
        cout<<"Masukkan nomor barang yang akan dirental\t: ";
        cin>>masukan[*urutan-1][1];
        if (masukan[*urutan-1][1] <= 5 && masukan[*urutan-1][1] > 0) {
            cout<<"Jumlah barang yang ingin dirental\t\t: ";
            cin>>masukan[*urutan-1][2];
            cout<<"Lama waktu/hari perentalan\t\t\t: ";
            cin>>masukan[*urutan-1][3];
        } else {
            salah ();
        }
    } else {
        salah ();
    }

    char ulang;
    cout<<"Tambah Barang? (y/n) ";
    cin>>ulang;

    switch (ulang) {
        case 'y':
            *urutan += 1;
            input(urutan);
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

void rincian (string brg[], int hrg[], int skg, int no, int jml, int hr, int *ttl) {
    int harga = hrg[no] * jml * hr;
    *ttl += harga;
    cout<<skg+1<<". "<<brg[no]<<"\t1pcs\tRp";
    pemisah(hrg[no]);
    cout<<"\n\t"<<jml<<"pcs\t"<<hr<<"hari\tRp";
    pemisah(harga);
}