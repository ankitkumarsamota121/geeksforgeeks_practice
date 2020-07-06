#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, m, n;
    int mat[10][10];
    cin >> t;
    while (t--) {
        cin >> m >> n;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                cin >> mat[r][c];
            }
        }

        int r = 0, c = 0;
        int r_start = 0, r_end = m - 1;
        int c_start = 0, c_end = n - 1;

        while (r_start <= r_end and c_start <= c_end) {
            // 1
            while (c <= c_end and r <= r_end) {
                cout << mat[r][c] << ' ';
                c++;
            }
            c--;
            r++;

            // 2
            while (r <= r_end and c >= c_start) {
                cout << mat[r][c] << ' ';
                r++;
            }
            c--;
            r--;

            // 3
            while (c >= c_start and r > r_start) {
                cout << mat[r][c] << ' ';
                c--;
            }
            c++;
            r--;

            // 4
            while (r > r_start and c < c_end) {
                cout << mat[r][c] << ' ';
                r--;
            }
            c++;
            r++;

            // cout << endl;

            r_start++;
            c_start++;

            r_end--;
            c_end--;
        }
        cout << endl;
    }
    return 0;
}