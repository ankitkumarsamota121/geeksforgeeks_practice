// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

long long int countSubarrWithEqualZeroAndOne(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++)
            cin >> arr[i];
        cout << countSubarrWithEqualZeroAndOne(arr, n) << "\n";
    }
    return 0;
}
// } Driver Code Ends

// arr[] : the input array
// N : size of the input array

// return the number of subarrays with equal 0s and 1s
long long int countSubarrWithEqualZeroAndOne(int arr[], int N) {
    //Your code here
    long long p[N + 1];
    p[0] = 0;

    for (long long i = 1; i <= N; i++) {
        p[i] = p[i - 1] + (arr[i - 1] == 0 ? -1 : 1);
    }

    map<long long, long long> m;

    for (int i = 0; i <= N; i++) {
        m[p[i]]++;
    }

    long long ans = 0;
    for (auto pr : m) {
        ans += (pr.second * (pr.second - 1)) / 2;
    }
    return ans;
}