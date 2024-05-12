#include <iostream>
#include <cmath>

using namespace std;

// Fungsi yang akan diintegrasikan
double func(double x) {
    return exp(x); // Misalnya, fungsi e^x
}

// Metode pias dengan kaidah segiempat
double segiempat(double a, double b, int n) {
    double h = (b - a) / n;
    double integral = 0.0;

    for (int i = 0; i < n; ++i) {
        double x0 = a + i * h;
        double x1 = a + (i + 1) * h;
        integral += func((x0 + x1) / 2) * h;
    }

    return integral;
}

// Metode pias dengan kaidah trapesium
double trapesium(double a, double b, int n) {
    double h = (b - a) / n;
    double integral = (func(a) + func(b)) / 2;

    for (int i = 1; i < n; ++i) {
        double x = a + i * h;
        integral += func(x);
    }

    integral *= h;
    return integral;
}

// Metode pias dengan kaidah titik tengah
double titikTengah(double a, double b, int n) {
    double h = (b - a) / n;
    double integral = 0.0;

    for (int i = 0; i < n; ++i) {
        double x = a + (i + 0.5) * h;
        integral += func(x) * h;
    }

    return integral;
}

int main() {
    double a, b;
    int n;

    cout << "Masukkan batas bawah a: ";
    cin >> a;
    cout << "Masukkan batas atas b: ";
    cin >> b;
    cout << "Masukkan jumlah subinterval n: ";
    cin >> n;

    // Menggunakan metode segiempat
    double integral_segiempat = segiempat(a, b, n);
    cout << "Hasil integral dengan metode segiempat: " << integral_segiempat << endl;

    // Menggunakan metode trapesium
    double integral_trapesium = trapesium(a, b, n);
    cout << "Hasil integral dengan metode trapesium: " << integral_trapesium << endl;

    // Menggunakan metode titik tengah
    double integral_titik_tengah = titikTengah(a, b, n);
    cout << "Hasil integral dengan metode titik tengah: " << integral_titik_tengah << endl;

    return 0;
}
