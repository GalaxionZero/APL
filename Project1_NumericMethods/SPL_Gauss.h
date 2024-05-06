#include <iostream>

using namespace std;

const int MAX_SIZE_GAUSS = 10; // Maksimum ukuran SPL

// Fungsi untuk mencetak matriks
void printMatrix(double matrix[MAX_SIZE_GAUSS][MAX_SIZE_GAUSS], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Metode eliminasi Gauss
void gaussElimination(double matrix[MAX_SIZE_GAUSS][MAX_SIZE_GAUSS], double constants[MAX_SIZE_GAUSS], int n) {
    for (int i = 0; i < n; ++i) {
        double pivot = matrix[i][i];

        for (int j = i + 1; j < n; ++j) {
            double ratio = matrix[j][i] / pivot;

            for (int k = i; k < n; ++k) {
                matrix[j][k] -= ratio * matrix[i][k];
            }

            constants[j] -= ratio * constants[i];
        }
    }

    double solution[MAX_SIZE_GAUSS];

    for (int i = n - 1; i >= 0; --i) {
        double sum = 0;

        for (int j = i + 1; j < n; ++j) {
            sum += matrix[i][j] * solution[j];
        }

        solution[i] = (constants[i] - sum) / matrix[i][i];
    }

    cout << "Solusi SPL:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "x" << i + 1 << " = " << solution[i] << endl;
    }
}

int main() {
    int n; // Jumlah persamaan dan variabel

    cout << "Masukkan jumlah persamaan dan variabel: ";
    cin >> n;

    double matrix[MAX_SIZE_GAUSS][MAX_SIZE_GAUSS]; // Matriks koefisien SPL
    double constants[MAX_SIZE_GAUSS];        // Vektor konstanta

    cout << "Masukkan koefisien SPL dan konstanta:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << "Koefisien baris ke-" << i + 1 << " kolom ke-" << j + 1 << ": ";
            cin >> matrix[i][j];
        }
        cout << "Konstanta vektor ke-" << i + 1 << ": ";
        cin >> constants[i];
    }

    cout << "\nMatriks Koefisien:" << endl;
    printMatrix(matrix, n);
    cout << "\nVektor Konstanta:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << constants[i] << endl;
    }

    gaussElimination(matrix, constants, n);

    return 0;
}
