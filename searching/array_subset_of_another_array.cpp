#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, m, n, a;
    cin >> t;
    while (t--) {
        cin >> m >> n;
        bool ans = true;
        unordered_map<int, int> A;

        for (int i = 0; i < m; i++) {
            cin >> a;
            A[a] = 1;
        }

        for (int i = 0; i < n; i++) {
            cin >> a;
            if (A[a] == 0) {
                ans = false;
            }
        }

        cout << (ans ? "Yes\n" : "No\n");
    }
    return 0;
}