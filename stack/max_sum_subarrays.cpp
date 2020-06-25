#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    int t, n;
    cin >> t;
    ll a[1005];
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        ll ans = -1;

        for (int i = 1; i < n; i++) {
            ans = max(ans, a[i - 1] + a[i]);
        }

        cout << ans << endl;
    }
    return 0;
}