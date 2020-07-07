#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll t, x, l, r, y;
    cin >> t;
    while (t--) {
        cin >> x >> l >> r >> y;
        ll maskLength = (1ll << (r - l + 1)) - 1;
        ll mask = ((maskLength) << (l - 1)) & y;
        x = (x | mask);
        cout << x << endl;
    }
    return 0;
}