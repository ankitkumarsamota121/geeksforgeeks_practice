#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll mod = 1000000001;

int main() {
    ll t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        ll *towers = new ll[n];
        for (int i = 0; i < n; i++) cin >> towers[i];

        stack<ll> s;
        ll ans = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (s.empty()) {
                s.push(towers[i]);
            } else {
                while (!s.empty() && s.top() <= towers[i]) {
                    s.pop();
                }
                ans += (s.empty() ? 0 : s.top());
                ans %= mod;
                s.push(towers[i]);
            }
        }

        cout << ans << endl;
    }
    return 0;
}