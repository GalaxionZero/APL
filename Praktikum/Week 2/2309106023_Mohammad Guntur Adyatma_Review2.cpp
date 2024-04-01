#include <iostream>
using namespace std;


int getMax(int arr[], int n)
{
    int maximum = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maximum)
        {
            maximum = arr[i];
        }
    }

    return maximum;
}

int getMin (int arr[], int n)
{
    int minimum = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < minimum)
        {
            minimum = arr[i];
        }
    }

    return minimum;
}

int main()
{
    int besarArray;
    cout << "Program Mencari Nilai Terbesar Dalam Sebuah Array\n\n";
    cout << "Masukkan besar array yang di inginkan: ";
    cin >> besarArray;
    int arr[besarArray], rataRata;

    for (int i = 0; i < besarArray; i++)
    {
        cout << "Masukkan angka untuk mengisi array ke-" << i << ": ";
        cin >> arr[i];
        rataRata += arr[i];
    }


    cout << "Nilai terbesar: " << getMax(arr, besarArray) << endl;
    cout << "Nilai terkecil: " << getMin(arr, besarArray) << endl;
    cout << "Rata-rata: " << rataRata / besarArray;

    return 0;
}
