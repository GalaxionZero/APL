#include <iostream>

using namespace std;

const int MAX_SIZE_JORDAN = 10;

void gaussJordan(double matrix[MAX_SIZE_JORDAN][MAX_SIZE_JORDAN], double constants[MAX_SIZE_JORDAN], int n)
{
    for (int i = 0; i < n; ++i)
    {
        // Proses pengulangan ke bawah
        for (int j = 0; j < n; ++j)
        {
            if (i != j)
            {
                double ratio = matrix[j][i] / matrix[i][i];
                for (int k = 0; k < n; ++k)
                {
                    matrix[j][k] -= ratio * matrix[i][k];
                }
                constants[j] -= ratio * constants[i];
            }
        }
    }

    // Membagi setiap baris dengan elemen diagonal untuk mendapatkan solusi
    for (int i = 0; i < n; ++i)
    {
        constants[i] /= matrix[i][i];
        matrix[i][i] = 1;
    }

    cout << "Solusi SPL:" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << "x" << i + 1 << " = " << constants[i] << endl;
    }
}
