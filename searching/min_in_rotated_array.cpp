#include <bits/stdc++.h>
using namespace std;

int findMin(int a[], int n, int s, int e) {
    // Base Case
    if (s >= e or a[s] <= a[e]) {
        return a[s];
    }

    // Recursive Case
    int mid = (s + e) / 2;
    if (a[mid] < a[s] and a[mid - 1] > a[mid]) {
        return a[mid];
    }
    if (a[mid] < a[s]) {
        return findMin(a, n, s, mid - 1);
    }
    return findMin(a, n, mid + 1, e);
}

int main() {
    int t, n;
    int a[1005];
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        cout << findMin(a, n, 0, n - 1) << endl;
    }
    return 0;
}