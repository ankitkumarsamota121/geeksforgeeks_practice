// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<int> sortByFreq(int arr[], int n);

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int a[n + 1];

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> v;
        v = sortByFreq(a, n);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends

//Complete this function
//Return the sorted array
bool compare(pair<int, int> p1, pair<int, int> p2) {
    if (p1.first == p2.first)
        return p1.second < p2.second;
    return p1.first > p2.first;
}

vector<int> sortByFreq(int arr[], int n) {
    //Your code here
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++) {
        m[arr[i]]++;
    }
    vector<pair<int, int>> v;
    for (auto p : m) {
        v.push_back({p.second, p.first});
    }

    sort(v.begin(), v.end(), compare);

    vector<int> res;
    for (auto p : v) {
        int temp = p.first;
        while (temp--) {
            res.push_back(p.second);
        }
    }
    return res;
}