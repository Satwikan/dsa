#include <iostream>
using namespace std;

void printArray(int arr[], int start, int end){
    for (int i = start; i < end; i++)
        cout << arr[i] << " ";
}

void selectionSort(int arr[], int start, int end) {
    int n = end;
    cout << "\nYour Array: ";
    printArray(arr, start, end);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                // swap
                int placeHolder = arr[j];
                arr[j] = arr[i];
                arr[i] = placeHolder;
            }
        }
    }
    cout << "\nSorted Array: ";
    printArray(arr, start, end);
}

int main()
{
    // Input numbers
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Sorting
    selectionSort(arr, 0, n);
    
}