// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

void merge(int arr1[], int arr2[], int n, int m) {
    int *arr3 = new int[n + m];
    int i = 0, j = 0, k = 0;

    while (i < n && j < m) {
        if (arr1[i] <= arr2[j]) {
            arr3[k] = arr1[i];
            i++;
            k++;
        } else {
            arr3[k] = arr2[j];
            j++;
            k++;
        }
    }

    while (i < n) {
        arr3[k] = arr1[i];
        i++;
        k++;
    }
    while (j < m) {
        arr3[k] = arr2[j];
        j++;
        k++;
    }

    for (int k = 0; k < n; k++) {
        arr1[k] = arr3[k];
    }
    for (int k = n; k < n + m; k++) {
        arr2[k - n] = arr3[k];
    }
}

// { Driver Code Starts.

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        int arr1[n], arr2[m];

        for (int i = 0; i < n; i++) {
            cin >> arr1[i];
        }

        for (int i = 0; i < m; i++) {
            cin >> arr2[i];
        }

        merge(arr1, arr2, n, m);

        for (int i = 0; i < n; i++)
            printf("%d ", arr1[i]);

        for (int i = 0; i < m; i++)
            printf("%d ", arr2[i]);

        cout << endl;
    }

    return 0;
}
// } Driver Code Ends