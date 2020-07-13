#include <bits/stdc++.h>
using namespace std;

int x, y, z, m;

// Bottom-Up Approach
int solveBU(int n) {
    int dp[10005]{0};
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        if (i >= x && dp[i - x] != -1)
            dp[i] = max(dp[i], dp[i - x] + 1);
        if (i >= y && dp[i - y] != -1)
            dp[i] = max(dp[i], dp[i - y] + 1);
        if (i >= z && dp[i - z] != -1)
            dp[i] = max(dp[i], dp[i - z] + 1);
    }

    return dp[n];
}

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> x >> y >> z;
        cout << solveBU(n) << endl;
    }
    return 0;
}