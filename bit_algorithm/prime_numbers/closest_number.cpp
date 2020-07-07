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

int findS(int n) {
    int d = 0;
    while (n > 0 and primes[n] == 0) {
        n--;
        d++;
    }
    return d;
}

int findL(int n) {
    int d = 0;
    while (primes[n] == 0) {
        n++;
        d++;
    }
    return d;
}

int main() {
    ll t, n;
    primeSieve();
    cin >> t;
    while (t--) {
        cin >> n;
        int s = findS(n);
        int l = findL(n);
        if (s <= l) {
            while (s--) n--;
        } else {
            while (l--) n++;
        }

        cout << n << endl;
    }
    return 0;
}