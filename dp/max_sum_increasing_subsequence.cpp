#include <bits/stdc++.h>
using namespace std;

int a[100005];
int dp[100005];

int LIS(int n) {
    for (int i = 0; i <= n; i++) {
        dp[i] = a[i];
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) {
                dp[i] = max(dp[i], dp[j] + a[i]);
            }
        }
        ans = max(dp[i], ans);
    }

    // for (int i = 0; i < n; i++) {
    //     cout << dp[i] << ' ';
    // }
    // cout << endl;

    return ans;
}

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << LIS(n) << endl;
    }
    return 0;
}