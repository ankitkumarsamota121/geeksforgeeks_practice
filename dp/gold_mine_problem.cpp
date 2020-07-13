#include <bits/stdc++.h>
using namespace std;

int mine[25][25]{0};
int dp[25][25]{0};

int max(int a, int b, int c) { return max(a, max(b, c)); }

int solve(int n, int m) {
    memset(dp[0], 0, sizeof(dp[0]));
    memset(dp[n + 1], 0, sizeof(dp[n + 1]));

    for (int i = 1; i <= n; i++) dp[i][m] = mine[i][m];

    for (int c = m - 1; c > 0; c--) {
        for (int r = 1; r <= n; r++) {
            dp[r][c] = max(dp[r - 1][c + 1], dp[r][c + 1], dp[r + 1][c + 1]) + mine[r][c];
        }
    }

    int ans = -1;

    for (int i = 1; i <= n; i++) ans = max(ans, dp[i][1]);

    return ans;
}

int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> mine[i][j];

        cout << solve(n, m) << endl;
        // for (int i = 0; i <= n; i++) {
        //     for (int j = 0; j <= m; j++)
        //         cout << dp[i][j];
        //     cout << endl;
        // }
    }
    return 0;
}