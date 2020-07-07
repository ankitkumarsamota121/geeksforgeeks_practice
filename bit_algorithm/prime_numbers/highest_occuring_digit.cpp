#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll primes[1000005]{0};

void primeSieve() {
    primes[0] = primes[1] = 0;
    primes[2] = 1;

    for (ll i = 3; i <= 1000005; i += 2) {
        primes[i] = 1;
    }

    for (ll i = 3; i <= 1000005; i += 2) {
        if (primes[i] == 1) {
            for (ll j = i * i; j <= 1000005; j += i) {
                primes[j] = 0;
            }
        }
    }
}

void countDigits(int n, int cnt[]) {
    while (n) {
        cnt[n % 10]++;
        n /= 10;
    }
}

int main() {
    ll t, l, r;
    primeSieve();
    cin >> t;
    while (t--) {
        int cnt[10]{0};
        cin >> l >> r;
        for (int i = l; i <= r; i++) {
            if (primes[i]) {
                countDigits(i, cnt);
            }
        }

        int m = -1;
        int ans = -1;
        for (int i = 0; i < 10; i++) {
            if (cnt[i] >= m and cnt[i] > 0) {
                m = cnt[i];
                ans = i;
            }
        }

        cout << ans << endl;
    }
    return 0;
}