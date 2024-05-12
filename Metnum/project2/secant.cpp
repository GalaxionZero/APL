#include <iostream>
#include <cmath>

using namespace std;

// Fungsi yang akan dicari akarnya
double func(double x) {
    return exp(x) - 5*x*x; // Fungsi e^x - 5x^2
}

// Implementasi metode Secant
double secantMethod(double x0, double x1, double tol, int maxIter) {
    double x_curr = x1;
    double x_prev = x0;

    for (int i = 0; i < maxIter; ++i) {
        double fx_curr = func(x_curr);
        double fx_prev = func(x_prev);

        // Perhitungan iterasi baru
        double x_next = x_curr - (fx_curr * (x_curr - x_prev)) / (fx_curr - fx_prev);

        // Cek kriteria berhenti
        if (abs(x_next - x_curr) < tol)
            return x_next;

        // Update nilai x
        x_prev = x_curr;
        x_curr = x_next;
    }

    cout << "Metode Secant tidak konvergen setelah " << maxIter << " iterasi." << endl;
    return -1;
}

int main() {
    double x0, x1, tol;
    int maxIter;

    cout << "Masukkan tebakan awal pertama: ";
    cin >> x0;
    cout << "Masukkan tebakan awal kedua: ";
    cin >> x1;
    cout << "Masukkan toleransi: ";
    cin >> tol;
    cout << "Masukkan jumlah maksimum iterasi: ";
    cin >> maxIter;

    double root = secantMethod(x0, x1, tol, maxIter);
    if (root != -1)
        cout << "Akar yang ditemukan: " << root << endl;

    return 0;
}
