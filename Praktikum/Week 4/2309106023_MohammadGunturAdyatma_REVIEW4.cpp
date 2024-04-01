#include <iostream>
using namespace std;


typedef struct
{
    string namaMahasiswa;
    string NIMMahasiswa;

}dataMahasiswa;


int main()
{
    dataMahasiswa mhs[2];

    for (int i = 0; i < 2; i++)
    {
        cout << "Masukkan nama mahasiswa pertama: ";
        getline(cin, mhs[i].namaMahasiswa);
        cout << "Masukkan NIM mahasiswa pertama: ";
        cin >> mhs[i].NIMMahasiswa;
        cin.ignore();
    }

    for (int i = 0; i < 2; i++)
    {
        cout << "Nama mahasiswa ke-" << i+1 << ": " << mhs[i].namaMahasiswa << endl;
        cout << "NIM mahasiswa ke-" << i+1 << ": " << mhs[i].NIMMahasiswa << endl;
    }


    return 0;
}
