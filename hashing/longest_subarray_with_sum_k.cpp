#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, k;
    int a[100005];
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        unordered_map<int, int> m;
        m[0] = -1;
        int sum = 0, ans = 0;

        for (int i = 0; i < n; i++) {
            sum += a[i];
            if (m.find(sum - k) != m.end()) {
                ans = max(ans, i - m[sum - k]);
            }
            if (m.find(sum) == m.end()) {
                m[sum] = i;
            }
        }

        cout << ans << endl;
    }
    return 0;
}