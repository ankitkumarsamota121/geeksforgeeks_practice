#include <bits/stdc++.h>
using namespace std;

#define int long long

int dp[100]{0};

void solve() {
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= 100; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    return;
}

int32_t main() {
    int t, n;
    cin >> t;
    solve();
    while (t--) {
        cin >> n;
        cout << dp[n] << endl;
    }
    return 0;
}