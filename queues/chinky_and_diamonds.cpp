#include <bits/stdc++.h>
using namespace std;

void a_k_s() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
}

int main() {
    a_k_s();

    int t, n, k, a;
    cin >> t;
    while (t--) {
        cin >> n >> k;

        priority_queue<int> pq;

        for (int i = 0; i < n; i++) {
            cin >> a;
            pq.push(a);
        }

        int ans = 0;

        for (int i = 0; i < k; i++) {
            int x = pq.top();
            pq.pop();
            ans += x;
            pq.push(x / 2);
        }

        cout << ans << endl;
    }

    return 0;
}