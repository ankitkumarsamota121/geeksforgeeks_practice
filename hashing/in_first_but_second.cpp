#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll t, n, m, b;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        ll a[n];
        unordered_map<ll, ll> B;
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (ll i = 0; i < m; i++) {
            cin >> b;
            B[b] = 1;
        }

        for (ll i = 0; i < n; i++) {
            if (B.count(a[i]) == 0) {
                cout << a[i] << ' ';
            }
        }
        cout << endl;
    }
    return 0;
}