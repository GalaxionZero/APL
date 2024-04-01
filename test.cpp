#include <iostream>
using namespace std;

// counting sort implementation
void countSort(int arr[], int n, int pos)
{
	// we declare a count array and initialize the array by 0
	int count[10] = { 0 };

	// we count the frequency of each distinct digit at given place for every element in the original array
	for (int i = 0; i < n; i++)
    {
		count[(arr[i] / pos) % 10]++;
	}

	// we perform prefix sum and update the count array
	for (int i = 1; i < 10; i++)
    {
		count[i] = count[i] + count[i - 1];
	}

	// we store our answer in the ans array
	int ans[n];
	for (int i = n - 1; i >= 0; i--)
    {
		ans[--count[(arr[i] / pos) % 10]] = arr[i];
	}

	// here we copy the contents of ans array to our original array
	for (int i = 0; i < n; i++)
    {
		arr[i] = ans[i];
	}
}


int findMax(int arr[], int n)
{
    int maxElement = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maxElement)
        {
            maxElement = arr[i];
        }
    }
    return maxElement;
}


// function to implement radix sort
void radixSort(int arr[], int n)
{
	int k = findMax(arr, n);

	for (int pos = 1; (k / pos) > 0; pos *= 10) {
		countSort(arr, n, pos);
	}
}


// driver code
int main()
{
	int arr[] = {6, 219, 670, 600, 1, 3, 67, 898, 54, 76};
	int n = sizeof(arr) / sizeof(arr[0]);
	radixSort(arr, n);

	// displaying the result
	cout << "Array after performing radix sort : " << endl;
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}



// Radix Sort in C++ Programming
/*
#include <iostream>
using namespace std;

// Function to get the largest element from an array
int getMax(int array[], int n) {
  int max = array[0];
  for (int i = 1; i < n; i++)
    if (array[i] > max)
      max = array[i];
  return max;
}

// Using counting sort to sort the elements in the basis of significant places
void countingSort(int array[], int size, int place) {
  const int max = 10;
  int output[size];
  int count[max];

  for (int i = 0; i < max; ++i)
    count[i] = 0;

  // Calculate count of elements
  for (int i = 0; i < size; i++)
    count[(array[i] / place) % 10]++;

  // Calculate cumulative count
  for (int i = 1; i < max; i++)
    count[i] += count[i - 1];

  // Place the elements in sorted order
  for (int i = size - 1; i >= 0; i--) {
    output[count[(array[i] / place) % 10] - 1] = array[i];
    count[(array[i] / place) % 10]--;
  }

  for (int i = 0; i < size; i++)
    array[i] = output[i];
}

// Main function to implement radix sort
void radixsort(int array[], int size) {
  // Get maximum element
  int max = getMax(array, size);

  // Apply counting sort to sort elements based on place value.
  for (int place = 1; max / place > 0; place *= 10)
    countingSort(array, size, place);
}

// Print an array
void printArray(int array[], int size) {
  int i;
  for (i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}

// Driver code
int main() {
  int array[] = {121, 432, 564, 23, 1, 45, 788};
  int n = sizeof(array) / sizeof(array[0]);
  radixsort(array, n);
  printArray(array, n);
}
*/
