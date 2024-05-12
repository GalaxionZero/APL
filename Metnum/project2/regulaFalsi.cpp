#include <iostream>
#include <cmath>

using namespace std;

// Fungsi yang akan dicari akarnya
double func(double x) {
    return exp(x) - 5*x*x; // Fungsi e^x - 5x^2
}

// Implementasi metode Regula Falsi
double regulaFalsi(double a, double b, double tol, int maxIteration) {
    if (func(a) * func(b) >= 0) {
        cout << "Tidak ada akar di dalam rentang ini!" << endl;
        return -1;
    }

    double c;
    int i = 0;
    while (fabs(b - a) >= tol && i <= maxIteration) {
        // Temukan titik perpotongan garis dengan sumbu x
        c = b - (func(b) * (b-a) / (func(b) - func(a)));

        // Cek jika c adalah akar
        if (func(c) == 0.00001 || a == c || b == c)
            break;
        else if (func(c)*func(a) < 0)
            b = c;
        else
            a = c;

        i++;
    }
    return c;
}

int main() {
    double a, b, tol;
    int maxIteration;
    cout << "Masukkan batas awal a: ";
    cin >> a;
    cout << "Masukkan batas akhir b: ";
    cin >> b;
    cout << "Masukkan toleransi: ";
    cin >> tol;
    cout << "Masukkan batas iterasi: ";
    cin >> maxIteration;

    double root = regulaFalsi(a, b, tol, maxIteration);
    if (root != -1)
        cout << "Akar yang ditemukan: " << root << endl;
    return 0;
}
