#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, s;
    int a[1005];
    cin >> t;
    while (t--) {
        cin >> n >> s;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a, a + n);

        bool flag = false;

        for (int i = 0; i < n; i++) {
            int sum = (s - a[i]);
            int l = 0;
            int h = n - 1;
            while (l < h) {
                if (l == i) l++;
                if (h == i) h--;

                if (a[l] + a[h] == sum) {
                    flag = true;
                    break;
                } else if (a[l] + a[h] > sum) {
                    h--;
                } else {
                    l++;
                }
            }
        }

        cout << flag << endl;
    }

    return 0;
}