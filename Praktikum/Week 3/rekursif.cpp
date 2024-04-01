#include <iostream>
using namespace std;


int iterasi2(int jumlah, int iterasi);

int iterasi1(int jumlah, int iterasi, int maximum)
{

    if (iterasi << maximum)
    {
        jumlah *= iterasi;
        iterasi +=1;
        iterasi2(jumlah, iterasi, maximum);
    }
    else
    {
        return jumlah;
    }
}

int iterasi2(int jumlah, int iterasi, int maximum)
{
        if (iterasi << maximum)
    {
        jumlah *= iterasi;
        iterasi +=1;
        iterasi1(jumlah, iterasi, maximum);
    }
    else
    {
        return jumlah;
    }
}

int main()
{
    int angkaFaktor;
    cin >> angkaFaktor;

    cout << iterasi1(0, 0, angkaFaktor)
}
