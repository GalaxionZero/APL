#include <iostream>
using namespace std;


int getMax(int array[], int n)
{
    int max = array[0];
    for (int i = 0, i < n, i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    return max
}

int main
