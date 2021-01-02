#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 5;
int main() {
    int t, n;
    vector<int> a(N);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<int> left(n);
        vector<int> right(n);

        for (int i = 0; i < n; i++) {
            left[i] = (i == 0 || left[i - 1] < a[i]) ? a[i] : left[i - 1];
        }

        for (int i = n - 1; i >= 0; i--) {
            right[i] = (i == n - 1 || right[i + 1] < a[i]) ? a[i] : right[i + 1];
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += (min(left[i], right[i]) - a[i]);
        }

        cout << ans << '\n';
    }
    return 0;
}