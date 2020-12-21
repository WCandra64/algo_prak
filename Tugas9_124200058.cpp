#include<iostream>
#include<iomanip>
using namespace std;

int max (float arr[], int sz), min (float arr[], int sz), selisih (float arr[], int sz);
float rata (float arr[], int sz);

main () {
    int selisih_max, ukuran;

    cout<<"Masukkan banyak angka : ";
    cin>>ukuran;

    float deret[ukuran];

    for (int i = 0; i < ukuran; i++)
    {
        cout<<"Angka ke-"<<i+1<<" : ";
        cin>>deret[i];
    }

    cout<<endl<<endl<<setfill('_')<<setw(5)<<'_'<<"Hasil"<<setfill('_')<<setw(5)<<'_';
    cout<<"\nDeret\t\t: ";

    for (int i = 0; i < ukuran; i++)
    {
        cout<<deret[i]<<" ";
    }

    cout<<"\nMaksimum\t: "<<max(deret, ukuran);
    cout<<"\nMinimum\t\t: "<<min(deret, ukuran);
    cout<<"\nRata-rata\t: "<<rata(deret, ukuran);
    cout<<"\nSelisih Max\t: "<<selisih(deret, ukuran);

    cout<<endl;
    system("pause");
}

int max (float arr[], int sz) {
    float maks = arr[0];

    for (int i = 0; i < sz; i++)
    {
        if (arr[i] > maks) maks = arr[i];
    }

    return maks;
}

int min (float arr[], int sz) {
    float min = arr[0];

    for (int i = 0; i < sz; i++)
    {
        if (arr[i] < min) min = arr[i];
    }

    return min;
}

float rata (float arr[], int sz) {
    float sums = 0;

    for (int i = 0; i < sz; i++)
    {
        sums += arr[i];
    }

    return sums / sz;
}

int selisih (float arr[], int sz) {
    int subs[sz];
    int subsMax = 0;

    for (int i = 0; i < sz-1; i++)
    {
        subs[i] = (arr[i] > arr[i+1] ? arr[i] - arr[i+1] : arr[i+1] - arr[i]);
        if (subs[i] > subsMax) subsMax = subs[i];
    }

    return subsMax;
}