// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function template for C++

class Solution {
   public:
    void reverseInGroups(vector<long long>& arr, int n, int k) {
        // code here
        for (int i = 0; i < n; i += k) {
            for (int x = i, y = min(n - 1, i + k - 1); x < y; x++, y--) {
                swap(arr[x], arr[y]);
            }
        }
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> arr;
        int k;
        cin >> k;

        for (long long i = 0; i < n; i++) {
            long long x;
            cin >> x;
            arr.push_back(x);
        }
        Solution ob;
        ob.reverseInGroups(arr, n, k);

        for (long long i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends