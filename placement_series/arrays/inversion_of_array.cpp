// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Function to find inversion count in the array

long long count(long long arr[], int s, int e) {
    int m = (s + e) / 2;
    int temp[e + 1];

    int i = s, j = m + 1, k = 0, cnt = 0;
    while (i <= m && j <= e) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            cnt += (m - i + 1);
            temp[k++] = arr[j++];
        }
    }

    while (i <= m)
        temp[k++] = arr[i++];

    while (j <= e)
        temp[k++] = arr[j++];

    i = s;
    k = 0;
    while (i <= e)
        arr[i++] = temp[k++];

    return cnt;
}

long long inversionCountUtil(long long arr[], int s, int e) {
    if (s == e) return 0;

    int m = (s + e) / 2;

    long long x = inversionCountUtil(arr, s, m);
    long long y = inversionCountUtil(arr, m + 1, e);
    long long z = count(arr, s, e);

    return x + y + z;
}

// arr[]: Input Array
// N : Size of the Array arr[]
long long int inversionCount(long long arr[], long long N) {
    // Your Code Here

    long long ans = inversionCountUtil(arr, 0, N - 1);

    return ans;
}

// { Driver Code Starts.

int main() {
    long long T;
    cin >> T;

    while (T--) {
        long long N;
        cin >> N;

        long long A[N];
        for (long long i = 0; i < N; i++) {
            cin >> A[i];
        }

        cout << inversionCount(A, N) << endl;
    }

    return 0;
}
// } Driver Code Ends