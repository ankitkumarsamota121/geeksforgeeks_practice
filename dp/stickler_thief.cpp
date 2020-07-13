#include <bits/stdc++.h>
using namespace std;

int a[10005]{0};
int dp[10005]{0};

// Top-Down Approach
int solve(int n) {
    // Base Case
    if (n <= 0) {
        return 0;
    }

    // Lookup
    if (dp[n] != 0) {
        return dp[n];
    }

    // Recursive Case
    int x = solve(n - 1);
    int y = solve(n - 2) + a[n];
    return dp[n] = max(x, y);
}

// Bottom-Up Approach
int solveBU(int n) {
    int dp[10005]{0};
    dp[1] = a[1];

    for (int i = 2; i <= n; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
    }

    return dp[n];
}

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        memset(dp, 0, sizeof(dp));

        cout << solveBU(n) << endl;
    }
    return 0;
}