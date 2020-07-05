// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<int> countDistinct(int[], int, int);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        vector<int> result = countDistinct(a, n, k);
        for (int i : result)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends

vector<int> countDistinct(int A[], int n, int k) {
    //code here.
    unordered_map<int, int> m;
    vector<int> v;

    for (int i = 0; i < k; i++) {
        m[A[i]]++;
    }

    v.push_back(m.size());

    int i = 0;
    int j = k - 1;
    while (j < n - 1) {
        m[A[i]]--;
        if (!m[A[i]]) m.erase(A[i]);
        m[A[j + 1]]++;
        v.push_back(m.size());
        i++;
        j++;
    }

    return v;
}