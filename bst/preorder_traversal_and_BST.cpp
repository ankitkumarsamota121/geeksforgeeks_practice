#include <bits/stdc++.h>
using namespace std;

bool canRepresentBST(int pre[], int n) {
    stack<int> s;

    int root = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (pre[i] < root)
            return false;

        while (!s.empty() && s.top() < pre[i]) {
            root = s.top();
            s.pop();
        }
        s.push(pre[i]);
    }
    return true;
}

int main() {
    int t, n;
    int pre[1005];
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> pre[i];

        cout << canRepresentBST(pre, n) << endl;
    }
    return 0;
}