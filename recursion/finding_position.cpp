#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int ans = 1;
        while (ans < n) {
            ans *= 2;
        }
        ans /= 2;
        cout << ans << endl;
    }
    return 0;
}