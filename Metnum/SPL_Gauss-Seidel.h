    #include <iostream>
#include <cmath>

using namespace std;

const int MAX_SIZE_SEIDEL = 10;

void printVectorSeidel(double vector[MAX_SIZE_SEIDEL], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << "x" << i + 1 << " = " << vector[i] << endl;
    }
}

void gaussSeidelMethod(double matrix[MAX_SIZE_SEIDEL][MAX_SIZE_SEIDEL], double constants[MAX_SIZE_SEIDEL], double solution[MAX_SIZE_SEIDEL], int n, double tolerance, int maxIterations)
{
    double x[MAX_SIZE_SEIDEL];
    double error;
    int iteration = 0;

    // Inisialisasi solusi awal
    for (int i = 0; i < n; ++i)
    {
        solution[i] = 0;
    }

    do
    {
        // Simpan solusi dari iterasi sebelumnya
        for (int i = 0; i < n; ++i)
        {
            x[i] = solution[i];
        }

        // Iterasi Gauss-Seidel
        for (int i = 0; i < n; ++i)
        {
            double sum1 = 0;
            double sum2 = 0;
            for (int j = 0; j < i; ++j)
            {
                sum1 += matrix[i][j] * solution[j];
            }
            for (int j = i + 1; j < n; ++j)
            {
                sum2 += matrix[i][j] * x[j];
            }
            solution[i] = (constants[i] - sum1 - sum2) / matrix[i][i];
        }

        error = 0;
        // Hitung error relatif
        for (int i = 0; i < n; ++i)
        {
            error += fabs(solution[i] - x[i]);
        }

        iteration++;

        // Cek batasan iterasi dan error
        if (iteration >= maxIterations || error <= tolerance)
        {
            break;
        }

    }while (true);

    cout << "Jumlah Iterasi: " << iteration << endl;
    cout << "Error: " << error << endl;
}

int mainGaussSeidel(double matrix[MAX_SIZE_SEIDEL][MAX_SIZE_SEIDEL], double constants[MAX_SIZE_SEIDEL], int n)
{
    double tolerance;
    int maxIterations;

    cout << "\nMasukkan toleransi error: ";
    cin >> tolerance;
    cout << "Masukkan jumlah maksimum iterasi: ";
    cin >> maxIterations;

    double solution[MAX_SIZE_SEIDEL];

    gaussSeidelMethod(matrix, constants, solution, n, tolerance, maxIterations);

    cout << "\nSolusi SPL:" << endl;
    printVectorSeidel(solution, n);

    return 0;
}
