#include <iostream>
#include "SPL_DecompositionLU.h"
#include "SPL_Gauss-Jordan.h"
#include "SPL_Gauss-Seidel.h"
#include "SPL_Gauss.h"
#include "SPL_InverseMatrix.h"
#include "SPL_Jacobi.h"

const int MAX_SIZE = 10;

void printMatrix(double matrix[MAX_SIZE][MAX_SIZE], int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void printInput(double matrix[MAX_SIZE][MAX_SIZE], double constants[MAX_SIZE], int n)
{
    cout << "\nMatriks Koefisien:" << endl;
    printMatrix(matrix, n);
    cout << "\nVektor Konstanta:" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << constants[i] << endl;
    }
}


int main()
{
    int pilihan, n;

    cout << "Masukkan jumlah persamaan dan variabel: ";
    cin >> n;

    double matrix[MAX_SIZE][MAX_SIZE];
    double constants[MAX_SIZE];

    cout << "Masukkan koefisien SPL dan konstanta:" << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << "Koefisien baris ke-" << i + 1 << " kolom ke-" << j + 1 << ": ";
            cin >> matrix[i][j];
        }
        cout << "Konstanta vektor ke-" << i + 1 << ": ";
        cin >> constants[i];
    }

    cout << endl << "1. Eliminasi Gauss\n"
                    "2. Gauss-Jordan\n"
                    "3. Inverse Matrix\n"
                    "4. Dekomposisi LU\n"
                    "5. Lelaran Jacobi\n"
                    "6. Gauss Seidel\n"
                    "Pilih metode yang ingin digunakan: ";
    cin >> pilihan;

    switch(pilihan)
    {
    case 1:
        printInput(matrix, constants, n);
        gaussElimination(matrix, constants, n);
        break;
    case 2:
        printInput(matrix, constants, n);
        gaussJordan(matrix, constants, n);
        break;
    case 3:
        printInput(matrix, constants, n);
        mainInvMatx(matrix, constants, n);
        break;
    case 4:
        printInput(matrix, constants, n);
        mainDekomposisiLu(matrix, constants, n);
        break;
    case 5:
        printInput(matrix, constants, n);
        mainJacobi(matrix, constants, n);
        break;
    case 6:
        printInput(matrix, constants, n);
        mainGaussSeidel(matrix, constants, n);
        break;

    return 0;
    }
}
