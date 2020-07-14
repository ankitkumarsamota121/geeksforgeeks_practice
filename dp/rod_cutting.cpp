#include <bits/stdc++.h>
using namespace std;

int a[105]{0};

int solve(int n) {
    int dp[105]{0};
    for (int i = 1; i <= n; i++) {
        int j = 1;
        dp[i] = a[i];
        while (j <= i / 2) {
            dp[i] = max(dp[i], dp[j] + dp[i - j]);
            j++;
        }
    }

    return dp[n];
}

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        cout << solve(n) << endl;
    }
    return 0;
}