#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll coins[100005];
ll dp[100005]{0};

// Bottom Up Approach
ll coinChangeBU(ll money, ll N) {
    for (ll i = 0; i <= money; i++) dp[i] = INT_MAX;
    dp[0] = 0;

    for (ll i = 0; i <= money; i++) {
        for (ll n = 0; n < N; n++) {
            if (coins[n] <= i)
                dp[i] = min(dp[i], dp[i - coins[n]] + 1);
        }
    }
    if (dp[money] == INT_MAX) {
        return -1;
    }
    return dp[money];
}

int main() {
    ll t, v, n;
    cin >> t;
    while (t--) {
        cin >> v >> n;
        for (ll i = 0; i < n; i++) cin >> coins[i];
        cout << coinChangeBU(v, n) << endl;
    }
    return 0;
}