// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findMaxDiff(int[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << findMaxDiff(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends

/*You are required to complete this method */
int findMaxDiff(int A[], int n) {
    //Your code here
    stack<int> s;
    int ls[n];
    int rs[n];

    // Left Smaller Array
    for (int i = 0; i < n; i++) {
        if (s.empty()) {
            ls[i] = 0;
            s.push(A[i]);
        } else if (s.top() < A[i]) {
            ls[i] = s.top();
            s.push(A[i]);
        } else {
            while (!s.empty() and s.top() >= A[i]) {
                s.pop();
            }
            ls[i] = (s.empty() ? 0 : s.top());
            s.push(A[i]);
        }
    }

    while (!s.empty()) s.pop();

    // Right Smaller Array
    for (int i = n - 1; i >= 0; i--) {
        if (s.empty()) {
            rs[i] = 0;
            s.push(A[i]);
        } else if (s.top() < A[i]) {
            rs[i] = s.top();
            s.push(A[i]);
        } else {
            while (!s.empty() and s.top() >= A[i]) {
                s.pop();
            }
            rs[i] = (s.empty() ? 0 : s.top());
            s.push(A[i]);
        }
    }

    int m = -1;
    for (int i = 0; i < n; i++) {
        m = max(abs(ls[i] - rs[i]), m);
    }

    return m;
}