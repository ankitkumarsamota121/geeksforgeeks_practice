#include <bits/stdc++.h>
using namespace std;

int values[1005]{0};
int weights[1005]{0};
int dp[1005][1005] = {0};

// Top-Down Approach
int knapsack(int n, int w) {
    // Check in dp grid
    if (dp[n][w] != -1) {
        return dp[n][w];
    }

    // Base Case
    if (w == 0 || n == 0) {
        return dp[n][w] = 0;
    }

    // Recursive Case
    int a = 0, b = 0;
    a = knapsack(n - 1, w);
    if (w >= weights[n]) {
        b = knapsack(n - 1, w - weights[n]) + values[n];
    }
    return dp[n][w] = max(a, b);
}

// Bottom-Up Approach
int knapsackBU(int n, int w) {
    int dp[n + 1][w + 1];

    for (int i = 0; i <= n; i++) dp[i][0] = 0;
    for (int i = 0; i <= w; i++) dp[0][i] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= w; j++) {
            if (j >= weights[i]) {
                dp[i][j] = max(dp[i - 1][j],
                               values[i] + dp[i - 1][j - weights[i]]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][w];
}

int main() {
    int t, n, w;
    cin >> t;
    while (t--) {
        cin >> n >> w;

        // Clear the DP Array
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= w; j++)
                dp[i][j] = -1;

        for (int i = 1; i <= n; i++)
            cin >> values[i];
        for (int i = 1; i <= n; i++)
            cin >> weights[i];

        cout << knapsackBU(n, w) << endl;
        // cout << knapsack(n, w) << endl;
    }
    return 0;
}
