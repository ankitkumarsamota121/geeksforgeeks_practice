#include <bits/stdc++.h>
using namespace std;

void floodFill(int mat[][100], int x, int y, int k, int n, int m, int c) {
    // Base Case
    if (x < 0 || y < 0 || x >= n || y >= m || mat[x][y] != c) {
        return;
    }

    // Recursive Case
    mat[x][y] = k;
    floodFill(mat, x - 1, y, k, n, m, c);
    floodFill(mat, x + 1, y, k, n, m, c);
    floodFill(mat, x, y - 1, k, n, m, c);
    floodFill(mat, x, y + 1, k, n, m, c);
}

int main() {
    int t, n, m, x, y, k;
    int mat[100][100];
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                cin >> mat[r][c];
            }
        }

        cin >> x >> y >> k;

        floodFill(mat, x, y, k, n, m, mat[x][y]);

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                cout << mat[r][c] << ' ';
            }
            // cout << endl;
        }
        cout << endl;
    }
    return 0;
}