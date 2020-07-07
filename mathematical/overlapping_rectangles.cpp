#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, a1, b1, a2, b2, p1, q1, p2, q2;
    cin >> t;
    while (t--) {
        cin >> a1 >> b1 >> a2 >> b2;
        cin >> p1 >> q1 >> p2 >> q2;

        bool ans = true;

        if (p1 > a2 || a1 > p2) ans = false;
        if (q2 > b1 || b2 > q1) ans = false;

        cout << ans << endl;
    }
    return 0;
}