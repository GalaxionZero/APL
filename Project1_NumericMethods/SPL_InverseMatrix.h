#include <iostream>
#include <iomanip>

using namespace std;

const int MAX_SIZE_INVERSE = 10; // Maksimum ukuran SPL

// Fungsi untuk mencetak matriks
void printMatrixInverse(double matrix[MAX_SIZE_INVERSE][MAX_SIZE_INVERSE], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << setw(10) << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Fungsi untuk mencetak vektor
void printVectorInverse(double vector[MAX_SIZE_INVERSE], int n) {
    for (int i = 0; i < n; ++i) {
        cout << "x" << i + 1 << " = " << vector[i] << endl;
    }
}

// Fungsi untuk mengalokasikan matriks identitas
void identityMatrix(double identity[MAX_SIZE_INVERSE][MAX_SIZE_INVERSE], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                identity[i][j] = 1;
            } else {
                identity[i][j] = 0;
            }
        }
    }
}

// Fungsi untuk menemukan matriks invers
void matrixInverse(double matrix[MAX_SIZE_INVERSE][MAX_SIZE_INVERSE], double inverse[MAX_SIZE_INVERSE][MAX_SIZE_INVERSE], int n) {
    double identity[MAX_SIZE_INVERSE][MAX_SIZE_INVERSE];
    identityMatrix(identity, n);

    // Transformasi matriks menjadi matriks identitas dengan operasi baris elementer
    for (int i = 0; i < n; ++i) {
        double pivot = matrix[i][i];

        // Bagi baris dengan pivot
        for (int j = 0; j < n; ++j) {
            matrix[i][j] /= pivot;
            identity[i][j] /= pivot;
        }

        // Gunakan operasi baris elementer untuk membuat elemen di luar diagonal menjadi 0
        for (int k = 0; k < n; ++k) {
            if (k != i) {
                double factor = matrix[k][i];
                for (int j = 0; j < n; ++j) {
                    matrix[k][j] -= factor * matrix[i][j];
                    identity[k][j] -= factor * identity[i][j];
                }
            }
        }
    }

    // Salin matriks identitas yang sudah tertransformasi menjadi matriks invers
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            inverse[i][j] = identity[i][j];
        }
    }
}

int mainInvMatx() {
    int n; // Jumlah persamaan dan variabel

    cout << "Masukkan jumlah persamaan dan variabel: ";
    cin >> n;

    double matrix[MAX_SIZE_INVERSE][MAX_SIZE_INVERSE]; // Matriks koefisien SPL
    double constants[MAX_SIZE_INVERSE];        // Vektor konstanta

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
    printMatrixInverse(matrix, n);
    cout << "\nVektor Konstanta:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << setw(10) << constants[i] << endl;
    }

    double inverse[MAX_SIZE_INVERSE][MAX_SIZE_INVERSE]; // Matriks invers
    matrixInverse(matrix, inverse, n);

    cout << "\nMatriks Invers:" << endl;
    printMatrixInverse(inverse, n);

    // Mengalikan matriks invers dengan vektor konstanta untuk mendapatkan solusi
    double solution[MAX_SIZE_INVERSE];
    for (int i = 0; i < n; ++i) {
        solution[i] = 0;
        for (int j = 0; j < n; ++j) {
            solution[i] += inverse[i][j] * constants[j];
        }
    }

    cout << "\nSolusi SPL:" << endl;
    printVectorInverse(solution, n);

    return 0;
}
