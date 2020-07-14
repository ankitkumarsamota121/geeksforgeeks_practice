#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll N = 1e5 + 5;

int main() {
    ll t, n;
    ll *a = new ll[N];
    ll *v = new ll[N];
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];

        stack<ll> S;

        for (int i = n - 1; i >= 0; i--) {
            if (S.empty()) {
                v[i] = -1;
                S.push(a[i]);
            } else {
                while (!S.empty() && S.top() < a[i]) {
                    S.pop();
                }
                v[i] = (S.empty() ? -1 : S.top());
                S.push(a[i]);
            }
        }

        for (int i = 0; i < n; i++) {
            cout << v[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}