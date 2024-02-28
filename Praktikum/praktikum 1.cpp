#include <iostream>
using namespace std;

int main()
{
    int a, b, operatorArit;

    printf("Masukkan angka pertama: ");
    cin >> a;
    printf("Masukkan angka kedua: ");
    cin >> b;
    printf("Masukkan operator(1. +/2. -): ");
    cin >> operatorArit;

    if (operatorArit == 1)
    {
        cout << a + b;
    } else
    {
        cout << a - b;
    }
    return 0;
}



/*int main()
{
    int a;
    cin >> a;
    a %= 2;
    if (a == 1)
    {
        printf("Angka bilangan ganjil");

    } else
    {
            printf("Angka bilangan genap");
    }


    return 0;
}*/

/*int main()
{
    string nama, jurusan;
    int umur;
    printf("Masukkan nama anda: ");
    getline(cin, nama);
    printf("Masukkan nama jurusan anda: ");
    getline(cin, jurusan);
    printf("Masukkan umur anda: ");
    cin >> umur;
    cout << "Nama: " << nama << endl;
    cout << "Jurusan: " << jurusan << endl;
    cout << "Umur: " << umur;


    return 0;
}
*/
