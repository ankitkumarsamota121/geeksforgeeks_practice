#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> l;

    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);

    for (auto it = l.begin(); it != l.end(); it++) {
        l.insert(it, *it + 1);
    }

    for (auto x : l) {
        cout << x << ' ';
    }
    cout << endl;
    return 0;
}