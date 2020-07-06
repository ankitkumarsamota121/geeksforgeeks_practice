#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    string n;
    cin >> t;
    cin.ignore(32767, '\n');
    while (t--) {
        cin >> n;
        bool b = next_permutation(n.begin(), n.end());
        if (b) {
            cout << n << endl;
        } else {
            cout << "not possible" << endl;
        }
    }
    return 0;
}