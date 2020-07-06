// { Driver Code Starts
// C program for implementation of Merge Sort
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

void merge(int arr[], int l, int m, int r);

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

/* Function to print an array */
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main() {
    int n, T, i;

    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);
        int arr[n + 1];
        for (i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        mergeSort(arr, 0, n - 1);
        printArray(arr, n);
    }
    return 0;
}  // } Driver Code Ends

/* The task is to complete merge() which is used
   in below mergeSort() */
/*   l is for left index and r is right index of the
   sub-array of arr to be sorted
void mergeSort(int arr[], int l, int r) {
    if (l < r)   {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
} */

// Merges two subarrays of arr[].  First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int a[], int l, int m, int r) {
    // Your code here
    int temp[100005];
    int i, j, k;
    i = k = l;
    j = m + 1;

    while (i <= m and j <= r) {
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        }
        if (a[i] > a[j]) {
            temp[k++] = a[j++];
        }
    }

    while (i <= m) temp[k++] = a[i++];
    while (j <= r) temp[k++] = a[j++];

    for (int i = l; i <= r; i++) {
        a[i] = temp[i];
    }
}