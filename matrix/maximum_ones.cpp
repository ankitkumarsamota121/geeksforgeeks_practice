#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, m;
    int mat[40][40];
    cin >> t;
    while (t--) {
        cin >> n >> m;
        int max_cnt = 0, cnt;
        int ans;

        for (int r = 0; r < n; r++) {
            cnt = 0;
            for (int c = 0; c < m; c++) {
                cin >> mat[r][c];
                if (mat[r][c] == 1) {
                    cnt++;
                }
            }
            if (cnt > max_cnt) {
                ans = r;
                max_cnt = cnt;
            }
        }

        cout << ans << endl;
    }
    return 0;
}