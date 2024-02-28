#include <iostream>
using namespace std;

double sisi1, sisi2, sisi3;

void klasifikasiSegitiga(double a, double b, double c)
{
    if (a + b <= c || a + c <= b || b + c <= a)
        {
        cout << "Sisi yang dimasukkan tidak dapat membentuk segitiga.\n";
    }
        else if (a == b || a == c || b == c)
        {
        cout << "Sisi yang dimasukkan membentuk segitiga sama kaki.\n";
    }
        else if (a*a + b*b == c*c || b*b + c*c == a*a || c*c + a*a == b*b)
        {
        cout << "Sisi yang dimasukkan membentuk segitiga siku-siku.\n";
    }
        else
        {
        cout << "Sisi yang dimasukkan membentuk segitiga sembarang.\n";
    }
}


int main()
{
    cout << "Masukkan sisi 1: ";
    cin >> sisi1;
    cout << "Masukkan sisi 2: ";
    cin >> sisi2;
    cout << "Masukkan sisi 3: ";
    cin >> sisi3;

    klasifikasiSegitiga(sisi1, sisi2, sisi3);


    return 0;
}

