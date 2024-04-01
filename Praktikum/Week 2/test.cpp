#include <iostream>
using namespace std;

int main()
{
    int jml = 0, index;
    string ulang = "y", pilihan;
    string mahasiswa[10];
    while (ulang == "y")
    {
        cout << "1. Tambah Data\n"
                "2. Ubah Data\n"
                "3. Hapus Data\n"
                "Pilih Menu: ";
        cin >> pilihan;

        if (pilihan == "1")
            {
                cin.ignore();
                cout << "Masukkan nama mahasiswa\n";
                getline(cin, mahasiswa[jml]);
                jml +=1;
            }

            else if (pilihan == "2")
            {
                for (int i = 0; i < jml; i++)
                    {
                        cout << "Data ke-" << i+1 << " Nama: " << mahasiswa[i] << endl;
                    }
                cin.ignore();
                cout << "Pilih Urutan: ";
                cin >> index;
                cout << "Masukkan nama mahasiswa\n";
                cin.ignore();
                getline(cin, mahasiswa[index-1]);
            }
            else if (pilihan == "3")
            {
                for (int i = 0; i < jml; i++)
                    {
                        cout << "Data ke-" << i+1 << " Nama: " << mahasiswa[i] << endl;
                    }
                cin.ignore();
                cout << "Pilih Urutan: ";
                cin >> index;

                for (int i = index-1; i < jml-1; i++)
                    mahasiswa[i] = mahasiswa[i+1];

                jml--;

            }
            else
            {
                cout << "Pilihan tidak ada";
            }


        for (int i = 0; i < jml; i++)
        {
            cout << "Data ke-" << i+1 << " Nama: " << mahasiswa[i] << endl;
        }


        cout << "Ulang? y/n";
        cin >> ulang;
        if (ulang != "y")
        {
            break;
        }

    }

    return 0;
}
