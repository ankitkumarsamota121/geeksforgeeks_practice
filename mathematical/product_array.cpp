#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    int a[1005];
    cin >> t;
    while (t--) {
        cin >> n;
        int prod[1005]{0};
        int p = 1;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] != 0) {
                p *= a[i];
            } else {
                cnt++;
            }
        }

        if (cnt == 0) {
            for (int i = 0; i < n; i++) {
                prod[i] = (p / a[i]);
            }
        }
        if (cnt == 1) {
            for (int i = 0; i < n; i++) {
                if (a[i] == 0) {
                    prod[i] = p;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            cout << prod[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}