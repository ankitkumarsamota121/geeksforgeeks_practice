#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll a[n];
        ll p[n + 1];
        map<ll, ll> m;

        p[0] = 0;
        m[0] = 1;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            p[i + 1] = p[i] + a[i];
            m[p[i + 1]]++;
        }

        ll ans = 0;

        for (auto pr : m) {
            ans += (pr.second * (pr.second - 1)) / 2;
        }

        cout << ans << endl;
    }

    return 0;
}