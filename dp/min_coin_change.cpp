#include <bits/stdc++.h>
using namespace std;

int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
const int N = 10;

int coinChangeGreedy(int money) {
    vector<int> v;
    int n = N - 1;
    while (money > 0) {
        while (money >= coins[n]) {
            v.push_back(coins[n]);
            money -= coins[n];
        }
        n--;
    }
    for (auto x : v) cout << x << ' ';
    cout << endl;
    return v.size();
}

int main() {
    int t, money;
    cin >> t;
    while (t--) {
        cin >> money;
        coinChangeGreedy(money);
    }
    return 0;
}