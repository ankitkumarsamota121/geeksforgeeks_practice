#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    int t, n, k, a;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        int A[105]{0};
        int ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> a;
            if (k - a > 0) {
                ans += A[k - a];
            }
            A[a]++;
        }
        cout << ans << endl;
    }
    return 0;
}