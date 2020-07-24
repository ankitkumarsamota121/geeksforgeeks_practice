#include <bits/stdc++.h>
using namespace std;

void leafNodes(vector<int> pre, int s, int e) {
    if (s > e) return;
    if (s == e) {
        cout << pre[s] << ' ';
        return;
    }

    int p;
    for (p = s + 1; p <= e; p++)
        if (pre[p] > pre[s])
            break;

    leafNodes(pre, s + 1, p - 1);
    leafNodes(pre, p, e);
}

int main() {
    int t, n, a;
    vector<int> pre;
    vector<int> in;

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a;
            pre.push_back(a);
        }

        leafNodes(pre, 0, n - 1);
        cout << endl;

        pre.clear();
        in.clear();
    }
    return 0;
}