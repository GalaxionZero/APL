#include <iostream>
using namespace std;

int main()
{
    string mobil = "Ferrari";
    string *ptr = &mobil;
    cout << mobil << endl;
    cout << &mobil << endl;
    cout << ptr << endl;
    *ptr = "Lamborghini";
    cout << mobil << endl;
    cout << &mobil << endl;
    cout << ptr << endl;
}
