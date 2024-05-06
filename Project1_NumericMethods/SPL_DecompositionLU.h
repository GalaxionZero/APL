#include <iostream>
#include <vector>

using namespace std;

const int MAX_SIZE_LU = 10; // Maksimum ukuran SPL

// Fungsi untuk mencetak matriks
void printMatrixLU(double matrix[MAX_SIZE_LU][MAX_SIZE_LU], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Fungsi untuk dekomposisi LU
void luDecomposition(double matrix[MAX_SIZE_LU][MAX_SIZE_LU], double lower[MAX_SIZE_LU][MAX_SIZE_LU], double upper[MAX_SIZE_LU][MAX_SIZE_LU], int n) {
    for (int i = 0; i < n; ++i) {
        // Matriks L memiliki diagonal utama yang berisi 1
        lower[i][i] = 1;

        // Bagian atas dari matriks L dan matriks U
        for (int j = i; j < n; ++j) {
            double sum = 0;
            for (int k = 0; k < i; ++k) {
                sum += (lower[i][k] * upper[k][j]);
            }
            upper[i][j] = matrix[i][j] - sum;
        }

        // Bagian bawah dari matriks L
        for (int j = i + 1; j < n; ++j) {
            double sum = 0;
            for (int k = 0; k < i; ++k) {
                sum += (lower[j][k] * upper[k][i]);
            }
            lower[j][i] = (matrix[j][i] - sum) / upper[i][i];
        }
    }
}

// Fungsi untuk menghitung solusi dengan LU decomposition
void solveWithLU(double lower[MAX_SIZE_LU][MAX_SIZE_LU], double upper[MAX_SIZE_LU][MAX_SIZE_LU], double constants[MAX_SIZE_LU], double solution[MAX_SIZE_LU], int n) {
    // Mendapatkan solusi dari Ly = b (subsitusi maju)
    double y[MAX_SIZE_LU];
    for (int i = 0; i < n; ++i) {
        double sum = 0;
        for (int j = 0; j < i; ++j) {
            sum += lower[i][j] * y[j];
        }
        y[i] = constants[i] - sum;
    }

    // Mendapatkan solusi dari Ux = y (subsitusi mundur)
    for (int i = n - 1; i >= 0; --i) {
        double sum = 0;
        for (int j = i + 1; j < n; ++j) {
            sum += upper[i][j] * solution[j];
        }
        solution[i] = (y[i] - sum) / upper[i][i];
    }
}

int mainDekomposisiLu() {
    int n; // Jumlah persamaan dan variabel

    cout << "Masukkan jumlah persamaan dan variabel: ";
    cin >> n;

    double matrix[MAX_SIZE_LU][MAX_SIZE_LU]; // Matriks koefisien SPL
    double constants[MAX_SIZE_LU];        // Vektor konstanta

    cout << "Masukkan koefisien SPL dan konstanta:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << "Koefisien a" << i + 1 << j + 1 << ": ";
            cin >> matrix[i][j];
        }
        cout << "Konstanta b" << i + 1 << ": ";
        cin >> constants[i];
    }

    cout << "\nMatriks Koefisien:" << endl;
    printMatrixLU(matrix, n);
    cout << "\nVektor Konstanta:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << constants[i] << endl;
    }

    double lower[MAX_SIZE_LU][MAX_SIZE_LU]; // Matriks Lower
    double upper[MAX_SIZE_LU][MAX_SIZE_LU]; // Matriks Upper
    luDecomposition(matrix, lower, upper, n);

    cout << "\nMatriks L:" << endl;
    printMatrixLU(lower, n);
    cout << "\nMatriks U:" << endl;
    printMatrixLU(upper, n);

    double solution[MAX_SIZE_LU]; // Solusi SPL
    solveWithLU(lower, upper, constants, solution, n);

    cout << "\nSolusi SPL:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "x" << i + 1 << " = " << solution[i] << endl;
    }

    return 0;
}
