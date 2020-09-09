#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll t, n, x;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<ll> a(n), pre(n + 1);
        unordered_map<ll, ll> m;
        pre[0] = 0;
        m[0] = 1;
        for (ll i = 1; i <= n; i++) {
            cin >> x;
            a.push_back(x);
            pre[i] = pre[i - 1] + x;
            m[pre[i]]++;
        }

        int ans = 0;
        for (auto p : m) {
            if (p.second > 1) {
                int temp = p.second;
                ans += (temp * (temp - 1)) / 2;
            }
        }
        cout << ans << endl;
    }
    return 0;
}