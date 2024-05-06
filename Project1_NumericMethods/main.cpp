#include <iostream>
#include <SPL_DecompositionLU.h>
#include <SPL_Gauss-Jordan.h>
#include <SPL_Gauss-Seidel.h>
#include <SPL_Gauss.h>
#include <SPL_InverseMatrix.h>
#include <SPL_Jacobi.h>


int main()
{
    int pilihan;
    cout << "1. Eliminasi Gauss\n"
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
        mainGauss();
        break;
    case 2:
        mainGaussJordan();
        break;
    case 3:
        mainInvMatx();
        break;
    case 4:
        mainDekomposisiLu();
        break;
    case 5:
        mainJacobi();
        break;
    case 6:
        mainGaussSeidel();
        break;



    return 0;
    }
}
