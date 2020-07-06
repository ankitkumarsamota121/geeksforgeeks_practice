#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    int a[1000005];
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int l, m, h;
        l = m = 0;
        h = n - 1;
        while (m <= h) {
            if (a[m] == 0) {
                swap(a[m], a[l]);
                m++;
                l++;
            } else if (a[m] == 2) {
                swap(a[m], a[h]);
                h--;
            } else {
                m++;
            }

            // cout << l << ' ' << h << endl;
        }
        for (int i = 0; i < n; i++) {
            cout << a[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}