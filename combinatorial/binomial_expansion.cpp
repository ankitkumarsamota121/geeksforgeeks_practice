#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll binomialCoeff(ll n, ll k) {
    if (k > n - k) {
        k = n - k;
    }

    ll res = 1;
    for (ll i = 0; i < k; i++) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

int main() {
    ll t, a, x, n;
    cin >> t;
    while (t--) {
        cin >> a >> x >> n;

        for (ll i = 0; i <= n; i++) {
            ll p = binomialCoeff(n, i);
            ll q = pow(a, n - i);
            ll r = pow(x, i);
            cout << (p * q * r) << ' ';
        }
        cout << endl;
    }
    return 0;
}