#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define ff first
#define ss second

int dp[1005][1005] = {0};

int knapsack(int n, int w, vector<pii> items) {
    // Base Case
    if (w == 0 || n == 0) {
        return 0;
    }

    // Recursive Case
    if (dp[n][w]) {
        return dp[n][w];
    }

    pii p = items[n];
    int a = 0, b = 0;
    if (n >= 1) {
        a = knapsack(n - 1, w, items);
        if (w >= p.ss) {
            b = p.ff + knapsack(n - 1, w - p.ss, items);
        }
    }
    return dp[n][w] = max(a, b);
}

int main() {
    int t, n, w, vi, wi;
    int a[1005];
    cin >> t;
    while (t--) {
        cin >> n >> w;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<pii> items;

        for (int i = 0; i < n; i++) {
            cin >> wi;
            items.push_back({a[i], wi});
        }

        cout << knapsack(n - 1, w, items) << endl;
    }
    return 0;
}