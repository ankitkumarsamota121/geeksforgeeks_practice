// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

//User function template for C++
class Solution {
   public:
    // Function to check if the
    // Pythagorean triplet exists or not
    bool checkTriplet(int arr[], int n) {
        // code here
        int v[1005] = {0};
        for (int i = 0; i < n; i++) {
            v[arr[i]]++;
        }

        vector<int> a;
        for (int i = 0; i <= 1000; i++) {
            if (v[i] > 0) a.push_back(i);
        }

        bool ans = false;
        for (int k = a.size() - 1; k >= 0; k--) {
            int i = 0;
            int j = k - 1;
            while (i <= j) {
                int temp = (a[i] * a[i]) + (a[j] * a[j]);
                if (i == j && v[a[i]] > 1 && (temp == a[k] * a[k])) {
                    ans = true;
                    break;
                } else if (temp == a[k] * a[k]) {
                    ans = true;
                    break;
                } else if (temp > a[k] * a[k]) {
                    j--;
                } else {
                    i++;
                }
            }
        }

        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.checkTriplet(arr, n);
        if (ans) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}
// } Driver Code Ends