#include <iostream>
#include <cmath>

using namespace std;

// Fungsi yang akan dicari akarnya
double func(double x) {
    return exp(x) - 5*x*x; // Fungsi e^x - 5x^2
}

// Implementasi metode bagi dua
double bisectionMethod(double a, double b, double tol) {
    if (func(a) * func(b) >= 0) {
        cout << "Tidak ada akar di dalam rentang ini!" << endl;
        return -1;
    }

    double c;
    while ((b-a) >= tol) {
        // Temukan titik tengah interval
        c = (a+b) / 2;

        // Cek jika c adalah akar
        if (func(c) == 0.00001)
            break;
        else if (func(c)*func(a) < 0)
            b = c;
        else
            a = c;
    }
    return c;
}

int main() {
    double a, b, tol;
    cout << "Masukkan batas awal a: ";
    cin >> a;
    cout << "Masukkan batas akhir b: ";
    cin >> b;
    cout << "Masukkan toleransi: ";
    cin >> tol;

    double root = bisectionMethod(a, b, tol);
    if (root != -1)
        cout << "Akar yang ditemukan: " << root << endl;
    return 0;
}
