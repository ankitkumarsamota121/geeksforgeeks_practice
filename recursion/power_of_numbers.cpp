#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll mod = 1000000007;

ll mPow(ll n, ll r) {
    ll res = 1;
    while (r) {
        if (r & 1) {
            res = (res * n) % mod;
        }
        n = (n * n) % mod;
        r >>= 1;
    }
    return res;
}

ll mPowRec(ll n, ll r) {
    // Base Case
    if (r == 0) {
        return 1;
    }

    // Recursive Case
    ll sub = mPowRec(n, r / 2) % mod;
    sub = (sub * sub) % mod;
    if (r & 1) {
        return (n * sub) % mod;
    }
    return sub;
}

ll reversDigits(ll num) {
    ll rev_num = 0;
    while (num > 0) {
        rev_num = rev_num * 10 + num % 10;
        num = num / 10;
    }
    return rev_num;
}

int main() {
    ll t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        ll r = reversDigits(n);
        // cout << mPowRec(n, r) << endl;
        cout << mPow(n, r) << endl;
    }
    return 0;
}