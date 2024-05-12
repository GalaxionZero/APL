#include <iostream>
#include <cmath>

using namespace std;

// Fungsi yang akan dicari akarnya
double func(double x) {
    return exp(x) - 5*x*x; // Fungsi e^x - 5x^2
}

// Turunan fungsi
double derivFunc(double x) {
    return exp(x) - 10*x; // Turunan dari fungsi e^x - 5x^2 adalah e^x - 10x
}

// Implementasi metode Newton-Raphson
double newtonRaphson(double x0, double tol, int maxIter) {
    double x = x0;

    for (int i = 0; i < maxIter; ++i) {
        double fx = func(x);
        double dfx = derivFunc(x);

        // Perhitungan iterasi baru
        double x_new = x - (fx / dfx);

        // Cek kriteria berhenti
        if (abs(x_new - x) < tol)
            return abs(x_new);

        // Update nilai x
        x = x_new;
    }

    cout << "Metode Newton-Raphson tidak konvergen setelah " << maxIter << " iterasi." << endl;
    return -1;
}

int main() {
    double x0, tol;
    int maxIter;

    cout << "Masukkan tebakan awal: ";
    cin >> x0;
    cout << "Masukkan toleransi: ";
    cin >> tol;
    cout << "Masukkan jumlah maksimum iterasi: ";
    cin >> maxIter;

    double root = newtonRaphson(x0, tol, maxIter);
    if (root != -1)
        cout << "Akar yang ditemukan: " << root << endl;

    return 0;
}
