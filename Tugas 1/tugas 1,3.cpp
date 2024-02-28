#include <iostream>
using namespace std;

int dimensi1, dimensi2, dimensi3;
double rataRata = 0;


void isiArray2D(int dimensi1, int dimensi2)
{
    int array[dimensi1][dimensi2];

    for (int i = 0; i < dimensi1; i++)
    {
        for (int j = 0; j < dimensi2; j++)
        {
            cout << "Masukkan nilai array ke-" << i << "," << j << ": ";
            cin >> array[i][j];

            rataRata += array[i][j];
        }
    }


    cout << "Array yang dimasukan adalah: \n";
    for (int i = 0; i < dimensi1; i++)
    {
        for (int j = 0; j < dimensi2 ; j++)
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Rata-rata dari array tersebut adalah: " << rataRata / (dimensi1 * dimensi2) << endl;
}


void isiArray3D(int dimensi1, int dimensi2, int dimensi3)
{
    int array[dimensi1][dimensi2][dimensi3];

    for (int i = 0; i < dimensi1; i++)
    {
        for (int j = 0; j < dimensi2; j++)
        {
            for (int k = 0; k < dimensi3; k++)
            {
                cout << "Masukkan nilai array ke-" << i << "," << j << "," << k << ": ";
                cin >> array[i][j][k];

                rataRata += array[i][j][k];
            }
        }
    }


    cout << "Array yang dimasukkan adalah: \n";
    for (int i = 0; i < dimensi1; i++)
    {
        for (int j = 0; j < dimensi2; j++)
        {
            for (int k = 0; k < dimensi3; k++)
            {
                cout << array[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    cout << "Rata-rata dari array tersebut adalah: " << rataRata / (dimensi1 * dimensi2 * dimensi3) << endl;
}


int main()
{
    cout << "Masukkan dimensi pertama array: ";
    cin >> dimensi1;
    cout << "Masukkan dimensi kedua array: ";
    cin >> dimensi2;
    cout << "Masukkan dimensi ketiga array: ";
    cin >> dimensi3;

    if (dimensi3 == 0)
        {
        isiArray2D(dimensi1, dimensi2);
    }
        else
        {
        isiArray3D(dimensi1, dimensi2, dimensi3);
    }


    return 0;

}
