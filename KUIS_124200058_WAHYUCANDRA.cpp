#include<iostream>
#include<iomanip>
using namespace std;

main () {
    int pilih, x = 0, y = 0, nim, rond;
    float rtrt, kuis, rspn, tgs, pryk;
    char nlhf, nama[30], nama2[30], nim2[9];
    string jrsn, gbk1, gbk2;
    
    cout<<"KUISS "<<setfill('=')<<setw(16)<<'='<<endl;
    cout<<"1. Deret Unik\n2. Nilai Akhir\n3. Gunting Batu Kertas (Bonus)\n4. Keluar";
    cout<<endl<<"Pilih: ";
    cin>>pilih;

    switch (pilih) {
        case 1:
            cout<<"X: ";
            cin>>x;
            cout<<"Y: ";
            cin>>y;
            cout<<endl;

            for (int i = 1; i <= y; i++)
            {
                i % x == 0 ? cout<<"|" : cout<<"-";
            }
            
            break;
        case 2:
            cout<<"Input Nilai Praktikum "<<setfill('=')<<setw(9)<<'='<<endl;
            cout<<"Nama\t\t: ";
            cin.ignore();
            cin.getline(nama, 30);
            cout<<"NIM\t\t: ";
            cin>>nim2;
            cout<<"Kuis\t\t: ";
            cin>>kuis;
            cout<<"Responsi\t: ";
            cin>>rspn;
            cout<<"Tugas\t\t: ";
            cin>>tgs;
            cout<<"Project\t\t: ";
            cin>>pryk;

            // x = nim / 1000000;
            switch (nim2[2]) {
                case '1':
                    jrsn = "Teknik Kimia";
                    break;
                case '2':
                    jrsn = "Teknik Industri";
                    break;
                case '3':
                    jrsn = "Informatika";
                    break;
                case '4':
                    jrsn = "Sistem Informasi";
                    break;
                default:
                    jrsn = "Salah Jurusan";
            }

            rtrt = (kuis / 5) + (7 * rspn / 20) + (3 * tgs / 20) + (3 * pryk / 10);

            if (rtrt < 20) nlhf = 'E';
            else if (rtrt < 40) nlhf = 'D';
            else if (rtrt < 60) nlhf = 'C';
            else if (rtrt < 80) nlhf = 'B';
            else if (rtrt <= 100) nlhf = 'A';
            else nlhf = '-';

            cout<<"\nHasil Akhir "<<setfill('=')<<setw(19)<<'='<<endl;
            cout<<"Nama\t\t: "<<nama<<"\nNIM\t\t: "<<nim2<<endl;
            cout<<"Jurusan\t\t: "<<jrsn<<"\nRata-rata\t: "<<rtrt<<endl;
            cout<<"Nilai Huruf\t: "<<nlhf<<endl;

            rtrt >= 60 ? cout<<"Selamat anda lulus praktikum" :
            cout<<"Mohon maaf anda belum lulus praktikum";

            break;
        case 3:
            cout<<"Masukkan nama player 1 : ";
            cin.ignore();
            cin.getline(nama, 30);
            cout<<"Masukkan nama player 2 : ";
            cin.getline(nama2, 30);
            cout<<"Masukkan banyak ronde : ";
            cin>>rond;
            cin.ignore();

            for (int i = 1; i <= rond; i++)
            {
                cout<<"\nRonde ke-"<<i<<endl;
                cout<<"Masukkan kertas/gunting/batu "<<nama<<" : ";
                cin>>gbk1;
                cout<<"Masukkan kertas/gunting/batu "<<nama2<<" : ";
                cin>>gbk2;

                gbk1 == "batu" ? (gbk2 == "kertas" ? y++ : (gbk2 == "gunting" ? x++ : x += 0)) :
                    (gbk1 == "kertas" ? (gbk2 == "gunting" ? y++ : (gbk2 == "batu" ? x++ : x += 0)) : 
                        (gbk1 == "gunting" ? (gbk2 == "batu" ? y++ : (gbk2 == "kertas" ? x++ : x += 0)) : 
                            x += 0));
            }
            
            cout<<"\n_____Hasil Akhir_____\n";
            cout<<nama<<" menang "<<x<<" kali\n";
            cout<<nama2<<" menang "<<y<<" kali\n";
            if (x == y) cout<<"Pertandingan seri";
            else 
            {
                cout<<"Jadi pemenangnya adalah ";
                x > y ? cout<<nama : cout<<nama2;
            }

            break;
        case 4:
            exit(0);
            break;
        default:
            cout<<"Mohon maaf anda salah input";
    }

    cout<<endl<<endl;
    system("pause");
}