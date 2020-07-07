#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll t, x;
    cin >> t;
    while (t--) {
        cin >> x;
        ll p = 0;
        ll res = 0;
        while (x) {
            p++;
            if (x & 1) {
                res = (res | (1ll << (32 - p)));
            }
            x >>= 1;
        }
        cout << res << endl;
    }
    return 0;
}