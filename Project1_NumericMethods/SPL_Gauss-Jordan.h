#include <iostream>

using namespace std;

const int MAX_SIZE_JORDAN = 10; // Maksimum ukuran SPL

// Fungsi untuk mencetak matriks
void printMatrixJordan(double matrix[MAX_SIZE_JORDAN][MAX_SIZE_JORDAN], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Metode Gauss-Jordan
void gaussJordan(double matrix[MAX_SIZE_JORDAN][MAX_SIZE_JORDAN], double constants[MAX_SIZE_JORDAN], int n) {
    for (int i = 0; i < n; ++i) {
        // Proses pengulangan ke bawah
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                double ratio = matrix[j][i] / matrix[i][i];
                for (int k = 0; k < n; ++k) {
                    matrix[j][k] -= ratio * matrix[i][k];
                }
                constants[j] -= ratio * constants[i];
            }
        }
    }

    // Membagi setiap baris dengan elemen diagonal untuk mendapatkan solusi
    for (int i = 0; i < n; ++i) {
        constants[i] /= matrix[i][i];
        matrix[i][i] = 1; // Diagonal menjadi 1
    }

    // Cetak solusi SPL
    cout << "Solusi SPL:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "x" << i + 1 << " = " << constants[i] << endl;
    }
}

int mainGaussJordan() {
    int n; // Jumlah persamaan dan variabel

    cout << "Masukkan jumlah persamaan dan variabel: ";
    cin >> n;

    double matrix[MAX_SIZE_JORDAN][MAX_SIZE_JORDAN]; // Matriks koefisien SPL
    double constants[MAX_SIZE_JORDAN];        // Vektor konstanta

    cout << "Masukkan koefisien SPL dan konstanta:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << "Koefisien baris ke-" << i + 1 << " kolom ke-" << j + 1 << ": ";
            cin >> matrix[i][j];
        }
        cout << "Konstanta ke-" << i + 1 << ": ";
        cin >> constants[i];
    }

    cout << "\nMatriks Koefisien:" << endl;
    printMatrixJordan(matrix, n);
    cout << "\nVektor Konstanta:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << constants[i] << endl;
    }

    gaussJordan(matrix, constants, n);

    return 0;
}
