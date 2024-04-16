#include <iostream>
using namespace std;

int main() {
    string nama;
    string data[9] = {"kucing", "kambing", "bebek", "ayam", "zebra"};
    cout << "masukkan nama yang di cari : ";
    getline(cin, nama); fflush(stdin);
    cout << endl;
    int i, akhir, awal, tengah;

    bool tukar = true;
    while (tukar == true)
    {
        tukar = false;
        for (i = 0; i < 10; i++)
        {
            if (data[i-1] > data[i])
            {
                string ok = data[i-1];
                data[i-1] = data[i];
                data[i] = ok;
                tukar = true;
            }
        }
    }


    awal = 0;
    akhir = 10;
    tengah = (awal + akhir)/2;

    while (true)
    {
        if (nama == data[tengah])
        {
            if (awal == akhir)
            {
                cout << i;
            }
            else if (nama < data[tengah])
            {
                akhir = tengah;
            }
        }
    }

    return 0;
}
