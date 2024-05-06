#include <iostream>
#include <cmath>

using namespace std;

const int MAX_SIZE_SEIDEL = 10; // Maksimum ukuran SPL

// Fungsi untuk mencetak matriks
void printMatrixSeidel(double matrix[MAX_SIZE_SEIDEL][MAX_SIZE_SEIDEL], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Fungsi untuk mencetak vektor
void printVectorSeidel(double vector[MAX_SIZE_SEIDEL], int n) {
    for (int i = 0; i < n; ++i) {
        cout << "x" << i + 1 << " = " << vector[i] << endl;
    }
}

// Metode Gauss-Seidel
void gaussSeidelMethod(double matrix[MAX_SIZE_SEIDEL][MAX_SIZE_SEIDEL], double constants[MAX_SIZE_SEIDEL], double solution[MAX_SIZE_SEIDEL], int n, double tolerance, int maxIterations) {
    double x[MAX_SIZE_SEIDEL]; // Solusi iterasi sebelumnya
    double error; // Error relatif
    int iteration = 0;

    // Inisialisasi solusi awal
    for (int i = 0; i < n; ++i) {
        solution[i] = 0;
    }

    do {
        // Simpan solusi dari iterasi sebelumnya
        for (int i = 0; i < n; ++i) {
            x[i] = solution[i];
        }

        // Iterasi Gauss-Seidel
        for (int i = 0; i < n; ++i) {
            double sum1 = 0;
            double sum2 = 0;
            for (int j = 0; j < i; ++j) {
                sum1 += matrix[i][j] * solution[j];
            }
            for (int j = i + 1; j < n; ++j) {
                sum2 += matrix[i][j] * x[j];
            }
            solution[i] = (constants[i] - sum1 - sum2) / matrix[i][i];
        }

        // Hitung error relatif
        error = 0;
        for (int i = 0; i < n; ++i) {
            error += fabs(solution[i] - x[i]);
        }

        iteration++;

        // Cek batasan iterasi dan error
        if (iteration >= maxIterations || error <= tolerance) {
            break;
        }

    } while (true);

    // Cetak informasi iterasi
    cout << "Jumlah Iterasi: " << iteration << endl;
    cout << "Error: " << error << endl;
}

int mainGaussSeidel() {
    int n; // Jumlah persamaan dan variabel
    double tolerance; // Toleransi error
    int maxIterations; // Jumlah maksimum iterasi

    cout << "Masukkan jumlah persamaan dan variabel: ";
    cin >> n;

    double matrix[MAX_SIZE_SEIDEL][MAX_SIZE_SEIDEL]; // Matriks koefisien SPL
    double constants[MAX_SIZE_SEIDEL];        // Vektor konstanta

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
    printMatrixSeidel(matrix, n);
    cout << "\nVektor Konstanta:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << constants[i] << endl;
    }

    cout << "\nMasukkan toleransi error: ";
    cin >> tolerance;
    cout << "Masukkan jumlah maksimum iterasi: ";
    cin >> maxIterations;

    double solution[MAX_SIZE_SEIDEL]; // Solusi SPL

    gaussSeidelMethod(matrix, constants, solution, n, tolerance, maxIterations);

    cout << "\nSolusi SPL:" << endl;
    printVectorSeidel(solution, n);

    return 0;
}
