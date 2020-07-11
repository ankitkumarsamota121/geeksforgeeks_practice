#include <bits/stdc++.h>
using namespace std;

int a[1005];
int dp[1005];

int LIS(int n) {
    for (int i = 0; i <= n; i++) {
        dp[i] = 1;
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(dp[i], ans);
    }

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