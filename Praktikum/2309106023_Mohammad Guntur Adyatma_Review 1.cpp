/*
Nama: Mohammad Guntur Adyatma;
NIM: 2309106023;
*/

#include <iostream>
using namespace std;

int main()
{
    int a, b, operatorArit;

    printf("Masukkan angka pertama: ");
    cin >> a;
    printf("Masukkan angka kedua: ");
    cin >> b;
    printf("Masukkan operator(1. + // 2. - // 3. * // 4. /): ");
    cin >> operatorArit;

    if (operatorArit == 1)
        {
        cout << a + b;
    }
        else if (operatorArit == 2)
        {
        cout << a - b;
    }
        else if (operatorArit == 3)
        {
        cout << a * b;
    }
        else
        {
        cout << a / b;
    }

    return 0;
}

