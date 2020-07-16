#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 5;

int main() {
    int t, n, k;
    int a[N];
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; i++) cin >> a[i];

        deque<int> Q;
        vector<int> V;

        int i = 0, j = 0;
        int mx = INT_MIN;
        // 1. Initialize the window and mx variable
        while (j < k) {
            mx = max(mx, a[j]);
            while (!Q.empty() && a[Q.back()] < a[j])
                Q.pop_back();

            Q.push_back(j);
            j++;
        }
        V.push_back(mx);

        // 2. Sliding Window
        while (j < n) {
            while (!Q.empty() && a[Q.back()] <= a[j])
                Q.pop_back();

            Q.push_back(j);

            while (Q.front() < (j - k + 1))
                Q.pop_front();

            V.push_back(a[Q.front()]);

            i++;
            j++;
        }

        for (int i = 0; i < V.size(); i++)
            cout << V[i] << ' ';
        cout << endl;
    }
    return 0;
}