#include <bits/stdc++.h>
using namespace std;

int main() {
    long long t, n, m;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<long long> a(n);
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> m;

        sort(a.begin(), a.end());
        long long ans = a[n - 1] - a[0];
        for (long long i = 0, j = m - 1; j < n; i++, j++) {
            ans = min(a[j] - a[i], ans);
        }

        cout << ans << '\n';
    }

    return 0;
}