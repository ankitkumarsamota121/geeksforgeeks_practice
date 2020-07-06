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

        sort(a, a + n);

        int ans = INT_MAX;

        int l = 0;
        int h = n - 1;
        while (l < h) {
            if (abs(a[l] + a[h]) < abs(ans)) {
                ans = a[l] + a[h];
            }
            if (a[l] + a[h] == 0) {
                break;
            } else if (a[l] + a[h] < 0) {
                l++;
            } else {
                h--;
            }
        }
        cout << ans << endl;
    }
    return 0;
}