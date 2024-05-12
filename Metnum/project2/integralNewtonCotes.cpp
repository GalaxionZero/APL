#include <iostream>
#include <cmath>

using namespace std;

// Fungsi yang akan diintegrasikan
double func(double x) {
    return exp(x); // Misalnya, fungsi e^x
}

// Metode Newton-Cotes dengan kaidah trapesium
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

// Metode Newton-Cotes dengan kaidah Simpson 1/3
double simpson1_3(double a, double b, int n) {
    double h = (b - a) / n;
    double integral = func(a) + func(b);

    for (int i = 1; i < n; i += 2) {
        double x = a + i * h;
        integral += 4 * func(x);
    }

    for (int i = 2; i < n - 1; i += 2) {
        double x = a + i * h;
        integral += 2 * func(x);
    }

    integral *= h / 3;
    return integral;
}

// Metode Newton-Cotes dengan kaidah Simpson 3/8
double simpson3_8(double a, double b, int n) {
    double h = (b - a) / n;
    double integral = func(a) + func(b);

    for (int i = 1; i < n; ++i) {
        double x = a + i * h;
        if (i % 3 == 0)
            integral += 2 * func(x);
        else
            integral += 3 * func(x);
    }

    integral *= 3 * h / 8;
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

    // Menggunakan metode kaidah trapesium
    double integral_trapesium = trapesium(a, b, n);
    cout << "Hasil integral dengan kaidah trapesium: " << integral_trapesium << endl;

    // Menggunakan metode kaidah Simpson 1/3
    double integral_simpson1_3 = simpson1_3(a, b, n);
    cout << "Hasil integral dengan kaidah Simpson 1/3: " << integral_simpson1_3 << endl;

    // Menggunakan metode kaidah Simpson 3/8
    double integral_simpson3_8 = simpson3_8(a, b, n);
    cout << "Hasil integral dengan kaidah Simpson 3/8: " << integral_simpson3_8 << endl;

    return 0;
}
