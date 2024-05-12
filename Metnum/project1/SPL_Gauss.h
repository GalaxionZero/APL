#include <iostream>

using namespace std;

const int MAX_SIZE_GAUSS = 10;

void gaussElimination(double matrix[MAX_SIZE_GAUSS][MAX_SIZE_GAUSS], double constants[MAX_SIZE_GAUSS], int n)
{
    for (int i = 0; i < n; ++i)
    {
        double pivot = matrix[i][i];

        // Iterasi untuk setiap baris matrix
        for (int j = i + 1; j < n; ++j)
        {
            double ratio = matrix[j][i] / pivot;

            // Lakukan eliminasi untuk setiap baris
            for (int k = i; k < n; ++k)
            {
                matrix[j][k] -= ratio * matrix[i][k];
            }

            constants[j] -= ratio * constants[i];
        }
    }

    double solution[MAX_SIZE_GAUSS];

    // Substitusi mundur untuk mencari solusi
    for (int i = n - 1; i >= 0; --i)
    {
        double sum = 0;

        for (int j = i + 1; j < n; ++j)
        {
            sum += matrix[i][j] * solution[j];
        }

        solution[i] = (constants[i] - sum) / matrix[i][i];
    }

    cout << "Solusi SPL:" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << "x" << i + 1 << " = " << solution[i] << endl;
    }
}
