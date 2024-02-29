#include <iostream>
using namespace std;

int dimensiTinggi, dimensiLebar, dimensiPanjang;
double rataRata = 0;


void isiArray3D(int dimensiTinggi, int dimensiLebar, int dimensiPanjang)
{
    int array[dimensiTinggi][dimensiLebar][dimensiPanjang];

    for (int i = 0; i < dimensiTinggi; i++)
    {
        for (int j = 0; j < dimensiPanjang; j++)
        {
            for (int k = 0; k < dimensiLebar; k++)
            {
                cout << "Masukkan nilai array ke-" << i << "," << j << "," << k << ": ";
                cin >> array[i][j][k];

                rataRata += array[i][j][k];
            }
        }
    cout << endl
    }


    cout << "Array yang dimasukkan adalah: \n";
    for (int i = 0; i < dimensiTinggi; i++)
    {
        for (int j = 0; j < dimensiLebar; j++)
        {
            for (int k = 0; k < dimensiPanjang; k++)
            {
                cout << array[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    cout << "Rata-rata dari array tersebut adalah: " << rataRata / (dimensiTinggi * dimensiLebar * dimensiPanjang) << endl;
}


int main()
{
    printf("Bayangkan array seperti sebuah balok! \n");
    cout << "Masukkan dimensi tinggi array: ";
    cin >> dimensiTinggi;
    cout << "Masukkan dimensi lebar array: ";
    cin >> dimensiLebar;
    cout << "Masukkan dimensi panjang array: ";
    cin >> dimensiPanjang;

    isiArray3D(dimensiTinggi, dimensiLebar, dimensiPanjang);


    return 0;

}
