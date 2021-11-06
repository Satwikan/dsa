#include<iostream>
using namespace std;

int unique(int arr[], int n) {

    int xorsum = 0;
    for (int i = 0; i < n; i++) {
        xorsum = xorsum ^ arr[i];
    }
    return xorsum;
}

/**
 * @return bool if at given position "pos" in n it it "1" or not
*/
int setBit(int n, int pos) {
    return ((1 << pos) & n);
}

void uniqueTwo(int arr[], int n) {
    int xorsum = 0;
    for (int i = 0; i < n; i++) {
        xorsum = xorsum ^ arr[i];
    }
    int x = xorsum;
    // find rightmost setbit
    int setbit = 0, pos = 0;
    while (setbit != 1) {
        setbit = xorsum & 1;
        pos++;
        xorsum = xorsum >> 1;
    }

    int a = 0;
    for (int i = 0; i < n; i++) {
        // check if arr[i] is 1 at pos
        if (setBit(arr[i], pos - 1)) {
            a = a ^ arr[i];
        }
    }
    cout << "1st unique number:" << a << endl;
    // b = x ^ a
    cout << "2nd unique number:" << (x ^ a) << endl;
}

int main() {

    // int arr[]={1, 2, 3, 1, 2, 3, 5, 7};
    int arr[] = { 1, 1, 2, 2, 3, 4, 5, 5 };

    uniqueTwo(arr, 8);
}
