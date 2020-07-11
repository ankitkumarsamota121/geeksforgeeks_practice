#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1e9 + 7;
int dp[105][105]{0};

ll countPaths(int m, int n) {
    // Check in dp grid
    if (dp[m][n] != 0) {
        return dp[m][n];
    }

    // Base Case
    if (m == 1 || n == 1) {
        return 1;
    }

    // Recursive Case
    return dp[m][n] = (countPaths(m - 1, n) + countPaths(m, n - 1)) % mod;
}

void countPathsBU() {
    int m = 100;
    int n = 100;
    // int dp[m + 1][n + 1];
    for (int i = 1; i <= m; i++) dp[i][1] = 1;
    for (int i = 1; i <= n; i++) dp[1][i] = 1;

    for (int i = 2; i <= m; i++) {
        for (int j = 2; j <= n; j++) {
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
        }
    }
}

int main() {
    int t, n, m;
    countPathsBU();
    cin >> t;
    while (t--) {
        cin >> n >> m;
        // cout << countPaths(m, n) << endl;
        // for (int i = 0; i <= m; i++) {
        //     for (int j = 0; j <= n; j++) {
        //         cout << dp[i][j] << ' ';
        //     }
        //     cout << endl;
        // }

        cout << dp[m][n] << endl;
    }
    return 0;
}