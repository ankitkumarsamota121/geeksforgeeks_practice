#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, s;
    cin >> t;
    while (t--) {
        cin >> n >> s;
        int max_sum = (n * 9);
        bool flag = (s > max_sum);
        string ans;
        while (n--) {
            if (s == 0) {
                ans += '0';
            } else if (s >= 9) {
                ans += '9';
                s -= 9;
            } else {
                ans += (s + '0');
                s = 0;
            }
        }

        if (ans[0] == '0' or flag) {
            cout << -1 << endl;
        } else {
            cout << ans << endl;
        }
    }
    return 0;
}