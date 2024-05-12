#include <iostream>
#include <iomanip>

using namespace std;

const int MAX_SIZE_INVERSE = 10;

void printMatrixInverse(double matrix[MAX_SIZE_INVERSE][MAX_SIZE_INVERSE], int n)
{
    for (int i = 0; i < n; ++i)
        {
        for (int j = 0; j < n; ++j)
        {
            cout << setw(10) << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void printVectorInverse(double vector[MAX_SIZE_INVERSE], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << "x" << i + 1 << " = " << vector[i] << endl;
    }
}


// Prosedur untuk mengalokasikan identitas matriks
void identityMatrix(double identity[MAX_SIZE_INVERSE][MAX_SIZE_INVERSE], int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i == j)
            {
                identity[i][j] = 1;
            }
                else
                {
                    identity[i][j] = 0;
                }
        }
    }
}

// Fungsi untuk menemukan matriks inverse
void matrixInverse(double matrix[MAX_SIZE_INVERSE][MAX_SIZE_INVERSE], double inverse[MAX_SIZE_INVERSE][MAX_SIZE_INVERSE], int n)
{
    double identity[MAX_SIZE_INVERSE][MAX_SIZE_INVERSE];
    identityMatrix(identity, n);

    // Transformasi matriks menjadi matriks identitas dengan operasi baris elementer
    for (int i = 0; i < n; ++i)
    {
        double pivot = matrix[i][i];

        // Bagi baris dengan pivot
        for (int j = 0; j < n; ++j)
        {
            matrix[i][j] /= pivot;
            identity[i][j] /= pivot;
        }

        // Gunakan operasi baris elementer untuk membuat elemen di luar diagonal menjadi 0
        for (int k = 0; k < n; ++k)
        {
            if (k != i)
            {
                double factor = matrix[k][i];
                for (int j = 0; j < n; ++j)
                {
                    matrix[k][j] -= factor * matrix[i][j];
                    identity[k][j] -= factor * identity[i][j];
                }
            }
        }
    }

    // Salin matriks identitas yang sudah tertransformasi menjadi matriks invers
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            inverse[i][j] = identity[i][j];
        }
    }
}

int mainInvMatx(double matrix[MAX_SIZE_INVERSE][MAX_SIZE_INVERSE], double constants[MAX_SIZE_INVERSE], int n)
{
    double inverse[MAX_SIZE_INVERSE][MAX_SIZE_INVERSE];
    matrixInverse(matrix, inverse, n);

    cout << "\nMatriks Invers:" << endl;
    printMatrixInverse(inverse, n);

    double solution[MAX_SIZE_INVERSE];
    for (int i = 0; i < n; ++i)
    {
        solution[i] = 0;
        for (int j = 0; j < n; ++j)
        {
            solution[i] += inverse[i][j] * constants[j];
        }
    }

    cout << "\nSolusi SPL:" << endl;
    printVectorInverse(solution, n);

    return 0;
}
