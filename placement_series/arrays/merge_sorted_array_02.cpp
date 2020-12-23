// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

void merge(int arr1[], int arr2[], int n, int m) {
    int gap = ceil((float)(n + m) / 2);
    while (gap) {
        int i = 0;
        int j = gap;

        while (j < n + m) {
            if (i >= n && arr2[i - n] > arr2[j - n]) {
                swap(arr2[i - n], arr2[j - n]);
            } else if (i < n && j >= n && arr1[i] > arr2[j - n]) {
                swap(arr1[i], arr2[j - n]);
            } else if (j < n && arr1[i] > arr1[j]) {
                swap(arr1[i], arr1[j]);
            }
            i++;
            j++;
        }
        if (gap <= 1) {
            gap = 0;
        } else {
            gap = (gap / 2) + (gap % 2);
        }
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