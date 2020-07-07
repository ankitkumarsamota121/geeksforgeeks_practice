#include <bits/stdc++.h>
using namespace std;

#define ll long long

void columnName(ll n, string out) {
    // Base Case
    if (n == 0) {
        cout << out << endl;
        return;
    }

    // Recursive Case
    out = char(((n - 1) % 26) + 'A') + out;
    columnName((n - 1) / 26, out);
}

int main() {
    ll t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        string out;

        columnName(n, out);
    }
    return 0;
}