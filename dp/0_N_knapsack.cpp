#include <bits/stdc++.h>
using namespace std;
int wts[1005]{0};
int val[1005]{0};

// Top Down Approach - Recursive
int solve(int n, int w) {
    // Base Case
    if (n == 0 || w == 0) {
        return 0;
    }

    // Recursive Case
    int x, y;
    x = y = 0;

    if (w >= wts[n]) {
        x = solve(n, w - wts[n]) + val[n];
    }
    return max(solve(n - 1, w), x);
}

int solveDP(int n, int w) {
    int dp[n + 1][w + 1];
    for (int i = 0; i <= w; i++) dp[0][i] = 0;
    for (int i = 0; i <= n; i++) dp[i][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= w; j++) {
            int x = 0;
            if (j >= wts[i]) {
                x = dp[i][j - wts[i]] + val[i];
            }
            dp[i][j] = max(dp[i - 1][j], x);
        }
    }

    return dp[n][w];
}

int main() {
    int t, n, w;
    cin >> t;
    while (t--) {
        cin >> n >> w;
        for (int i = 1; i <= n; i++) cin >> val[i];
        for (int i = 1; i <= n; i++) cin >> wts[i];
        // cout << solve(n, w) << endl;
        cout << solveDP(n, w) << endl;
    }
}