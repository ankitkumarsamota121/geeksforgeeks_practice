// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Functiuon to return number of trees

// Return the total number of BSTs possible with keys [1....N] inclusive.
// #define ll long long
long long numTrees(long long N) {
    // Your code here
    long long dp[1005];
    dp[0] = 1;
    for (int i = 1; i <= N; i++) {
        dp[i] = 0;
        for (int j = 0; j < i; j++) {
            dp[i] += (dp[j] * dp[i - j - 1]) % 1000000007;
            dp[i] %= 1000000007;
        }
    }

    return dp[N];
}

// { Driver Code Starts.
#define mod (int)(1e9 + 7)
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << numTrees(n) << "\n";
    }
}  // } Driver Code Ends