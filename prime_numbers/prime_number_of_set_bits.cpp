#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if (n == 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int t, l, r;
    cin >> t;
    while (t--) {
        cin >> l >> r;
        int ans = 0;
        for (int i = l; i <= r; i++) {
            int c = __builtin_popcount(i);
            if (isPrime(c)) {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}