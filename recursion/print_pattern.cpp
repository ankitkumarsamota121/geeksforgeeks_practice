#include <bits/stdc++.h>
using namespace std;

void printPattern(int n) {
    // Base Case
    if (n <= 0) {
        cout << n << ' ';
        return;
    }

    // Recursive Case
    cout << n << ' ';
    printPattern(n - 5);
    cout << n << ' ';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        printPattern(n);
        cout << endl;
    }
    return 0;
}