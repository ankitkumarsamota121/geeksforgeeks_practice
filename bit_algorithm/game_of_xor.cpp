#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    int a[1005];
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int ans = 0;
        if (n & 1) {
            for (int i = 0; i < n; i += 2) {
                ans ^= a[i];
            }
        }
        cout << ans << endl;
    }
    return 0;
}