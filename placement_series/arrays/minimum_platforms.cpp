// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int findPlatform(int arr[], int dep[], int n) {
    // Your code here
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        v.push_back({arr[i], 0});
    }

    for (int i = 0; i < n; i++) {
        v.push_back({dep[i], 1});
    }

    sort(v.begin(), v.end());

    int ans = 0, cnt = 0;
    for (auto p : v) {
        if (p.second == 0) {
            cnt++;
        } else {
            cnt--;
        }
        ans = max(ans, cnt);
    }

    return ans;
}

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        int dep[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int j = 0; j < n; j++) {
            cin >> dep[j];
        }
        cout << findPlatform(arr, dep, n) << endl;
    }
    return 0;
}  // } Driver Code Ends