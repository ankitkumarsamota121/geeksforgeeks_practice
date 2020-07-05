#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll t, n, k;
    ll a[100005];

    cin >> t;
    while (t--) {
        cin >> n >> k;

        unordered_map<ll, ll> m;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (m[a[i]] > 0) {
                k--;
            } else {
                m[a[i]] = 1;
            }
        }

        while (k > 0) {
            m.erase((*m.begin()).first);
            k--;
        }

        cout << m.size() << endl;
    }
    return 0;
}