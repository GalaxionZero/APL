#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
struct mahasiswa{
    string nama;
    int nim;
    double ipk;
};

mahasiswa mhs[10];

int main()
{
    // deklarasi file
    ofstream fileout;
    // membuka file
    fileout.open("data.csv", ios::out | ios::trunc);
    cout << "Masukkan Nama : "; getline(cin, mhs[0].nama);
    cout << "Masukkan NIM : "; cin >> mhs[0].nim;
    cout << "Masukkan IPK : "; cin >> mhs[0].ipk;
    // menulis data dari struct ke file
    fileout << mhs[0].nama << ",";
    fileout << mhs[0].nim << ",";
    fileout << mhs[0].ipk << "\n";
    // menutup file
    fileout.close();

    string data, nama, ipk, nim;
    int idx = 0, nim_int;
    double ipk_double;

    ifstream filein;
    filein.open("data.csv", ios::in);
    if (filein.is_open())
    {
        while (getline(filein, data))
        {
            stringstream ss(data);
            getline(ss, nama, ',');
            getline(ss, nim, ',');
            getline(ss, ipk, '\n');
            stringstream nim_string(nim);
            stringstream ipk_string(ipk);
            nim_string >> nim_int;
            ipk_string >> ipk_double;

            mhs[idx].nama = nama;
            mhs[idx].nim = nim_int;
            mhs[idx].ipk = ipk_double;

            idx++;
        }
    }

    filein.close();
    for (int i = 0; i < idx; i++)
    {
        cout << "Mahasiswa ke-" << i+1 << endl;
        cout << "Nama: " << mhs[i].nama << endl;
        cout << "NIM: " << mhs[i].nim << endl;
        cout << "IPK: " << mhs[i].ipk << endl;
    }

    return 0;
}
