#include <iostream>
using namespace std;


int volume(int panjang, int lebar, int tinggi)
{
    return panjang * lebar * tinggi;
}


int main()
{
    int panjang, lebar, tinggi;
    cout << "Panjang: ";
    cin >> panjang;
    cout << "Lebar: ";
    cin >> lebar;
    cout << "Tinggi: ";
    cin >> tinggi;

    cout << "Volume: " << volume(panjang, lebar, tinggi);
}
