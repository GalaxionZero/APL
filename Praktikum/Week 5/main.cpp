#include <iostream>
using namespace std;

int persegi(int *x)
{
    return *x;
}

int main()
{
    int a = 10;
    cout << persegi(&a) * 4;
}
