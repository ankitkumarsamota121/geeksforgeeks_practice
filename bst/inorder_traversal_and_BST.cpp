#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    int a[500];
    cin >> t;
    while (t--) {
        cin >> n;
        bool ans = true;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (i > 0 and a[i] <= a[i - 1]) {
                ans = false;
            }
        }

        cout << ans << endl;
    }
}