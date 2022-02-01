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
 * @return {bool} if at given position "pos" in n is "1" or not
*/
bool getBit(int n, int pos) {
    return ((1 << pos) & n) != 0;
}

/**
 * @return {integer} n with 1 at position "pos"
*/
int setBit(int n, int pos) {
    return (n | (1 << pos));
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
        if (getBit(arr[i], pos - 1)) {
            a = a ^ arr[i];
        }
    }
    cout << "1st unique number:" << a << endl;
    // b = x ^ a
    cout << "2nd unique number:" << (x ^ a) << endl;
}

void uniqueThrice(int arr[], int n) {
    int result = 0;
    for (int i = 0; i < 64; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++)
            if (getBit(arr[j], i))
                sum++;

        if (sum % 3 != 0)
            result = setBit(result, i);
    }
    cout << "result of uniqueThrice: " << result << endl;
}

int main() {

    // param for unique twice
    // int arr[] = { 1, 2, 3, 1, 2, 3, 5, 7 };
    // int arr[] = { 1, 1, 2, 2, 3, 4, 5, 5 };
    // uniqueTwo(arr, 8);

    // param for unique thrice
    int arr[] = { 1, 1, 1, 3, 3, 8, 3, 2, 2, 5, 5, 2, 5 };
    uniqueThrice(arr, 13);

}
