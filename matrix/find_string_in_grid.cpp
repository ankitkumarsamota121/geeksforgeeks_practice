#include <bits/stdc++.h>
using namespace std;

int t, n, m;

bool find1(char G[][100], char s[], int i, int r, int c) {
    if (s[i] == '\0') return true;
    if (r < 0 || c < 0 || r >= n || c >= m || G[r][c] != s[i]) return false;
    return find1(G, s, i + 1, r - 1, c - 1);
}

bool find2(char G[][100], char s[], int i, int r, int c) {
    if (s[i] == '\0') return true;
    if (r < 0 || c < 0 || r >= n || c >= m || G[r][c] != s[i]) return false;
    return find2(G, s, i + 1, r - 1, c);
}

bool find3(char G[][100], char s[], int i, int r, int c) {
    if (s[i] == '\0') return true;
    if (r < 0 || c < 0 || r >= n || c >= m || G[r][c] != s[i]) return false;
    return find3(G, s, i + 1, r - 1, c + 1);
}

bool find4(char G[][100], char s[], int i, int r, int c) {
    if (s[i] == '\0') return true;
    if (r < 0 || c < 0 || r >= n || c >= m || G[r][c] != s[i]) return false;
    return find4(G, s, i + 1, r, c + 1);
}

bool find5(char G[][100], char s[], int i, int r, int c) {
    if (s[i] == '\0') return true;
    if (r < 0 || c < 0 || r >= n || c >= m || G[r][c] != s[i]) return false;
    return find5(G, s, i + 1, r + 1, c + 1);
}

bool find6(char G[][100], char s[], int i, int r, int c) {
    if (s[i] == '\0') return true;
    if (r < 0 || c < 0 || r >= n || c >= m || G[r][c] != s[i]) return false;
    return find6(G, s, i + 1, r + 1, c);
}

bool find7(char G[][100], char s[], int i, int r, int c) {
    if (s[i] == '\0') return true;
    if (r < 0 || c < 0 || r >= n || c >= m || G[r][c] != s[i]) return false;
    return find7(G, s, i + 1, r + 1, c - 1);
}

bool find8(char G[][100], char s[], int i, int r, int c) {
    if (s[i] == '\0') return true;
    if (r < 0 || c < 0 || r >= n || c >= m || G[r][c] != s[i]) return false;
    return find8(G, s, i + 1, r, c - 1);
}

int main() {
    char s[100];
    char G[100][100];

    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                cin >> G[r][c];
            }
        }
        cin >> s;
        vector<pair<int, int>> v;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                bool a = find1(G, s, 0, r, c);
                bool b = find2(G, s, 0, r, c);
                bool i = find3(G, s, 0, r, c);
                bool d = find4(G, s, 0, r, c);
                bool e = find5(G, s, 0, r, c);
                bool f = find6(G, s, 0, r, c);
                bool g = find7(G, s, 0, r, c);
                bool h = find8(G, s, 0, r, c);
                if (a or b or i or d or e or f or g or h) {
                    v.push_back({r, c});
                }
            }
        }

        if (v.size() == 0) {
            cout << -1 << endl;
        } else {
            for (auto p : v) {
                cout << p.first << ' ' << p.second << ", ";
            }
            cout << endl;
        }
    }
    return 0;
}