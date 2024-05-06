#include <iostream>
#include <cmath>

using namespace std;

const int MAX_SIZE_JACOBI = 10;

void printVectorJacobi(double vector[MAX_SIZE_JACOBI], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << "x" << i + 1 << " = " << vector[i] << endl;
    }
}

void jacobiMethod(double matrix[MAX_SIZE_JACOBI][MAX_SIZE_JACOBI], double constants[MAX_SIZE_JACOBI], double solution[MAX_SIZE_JACOBI], int n, double tolerance, int maxIterations)
{
    double x[MAX_SIZE_JACOBI];
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

        // Iterasi Jacobi
        for (int i = 0; i < n; ++i)
        {
            double sum = 0;
            for (int j = 0; j < n; ++j)
            {
                if (j != i)
                {
                    sum += matrix[i][j] * x[j];
                }
            }
            solution[i] = (constants[i] - sum) / matrix[i][i];
        }

        // Hitung error relatif
        error = 0;
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

int mainJacobi(double matrix[MAX_SIZE_JACOBI][MAX_SIZE_JACOBI], double constants[MAX_SIZE_JACOBI], int n)
{
    double tolerance;
    int maxIterations;
    cout << "\nMasukkan toleransi error: ";
    cin >> tolerance;
    cout << "Masukkan jumlah maksimum iterasi: ";
    cin >> maxIterations;

    double solution[MAX_SIZE_JACOBI];

    jacobiMethod(matrix, constants, solution, n, tolerance, maxIterations);

    cout << "\nSolusi SPL:" << endl;
    printVectorJacobi(solution, n);

    return 0;
}
