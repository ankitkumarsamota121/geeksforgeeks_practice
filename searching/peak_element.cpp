// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/* The function should return the index of any
   peak element present in the array */

// arr: input array
// n: size of array

int peakElementUtil(int a[], int s, int e) {
    // Base Case
    if (s == e) {
        return s;
    }
    if (a[s] >= a[s + 1]) {
        return s;
    }
    if (a[e] >= a[e - 1]) {
        return e;
    }

    // Recursive Case
    int mid = (s + e) / 2;
    if (a[mid] >= a[mid - 1] and a[mid] >= a[mid + 1]) {
        return mid;
    }
    if (a[mid] < a[mid + 1]) {
        return peakElementUtil(a, mid + 1, e);
    }
    return peakElementUtil(a, s, mid - 1);
}

int peakElement(int arr[], int n) {
    // Your code here
    return peakElementUtil(arr, 0, n - 1);
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        bool f = 0;
        int A = peakElement(a, n);

        if (n == 1)
            f = 1;
        else if (A == 0 and a[0] >= a[1])
            f = 1;
        else if (A == n - 1 and a[n - 1] >= a[n - 2])
            f = 1;
        else if (a[A] >= a[A + 1] and a[A] >= a[A - 1])
            f = 1;
        else
            f = 0;

        cout << f << endl;
    }

    return 0;
}  // } Driver Code Ends