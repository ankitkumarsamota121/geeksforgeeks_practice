#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        ll ans = 0;
        for (ll i = 1; i * i <= n; i++) {
            ans++;
        }

        cout << ans << endl;
    }
    return 0;
}