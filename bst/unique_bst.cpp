#include <bits/stdc++.h>
using namespace std;

#define int long long

int nCr(int n, int r) {
    int num = 1;
    int den = 1;

    for (int i = 1, j = n; i <= r; i++, j--) {
        int g = __gcd(i, j);
        num *= (j / g);
        den *= (i / g);
    }

    return (num / den);
}

int32_t main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        cout << nCr(2 * n, n) / (n + 1) << endl;
    }
    return 0;
}