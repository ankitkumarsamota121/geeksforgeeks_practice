#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 5;

int main() {
    int t, n, s;
    int* a = new int[N];
    cin >> t;
    while (t--) {
        cin >> n >> s;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int i = 0, j = 0;
        int temp = 0;
        while (j <= n) {
            if (temp > s) {
                temp -= a[i];
                i++;
            } else if (temp < s) {
                temp += a[j];
                j++;
            } else {
                break;
            }
        }

        if (temp == s) {
            cout << i + 1 << ' ' << j << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}