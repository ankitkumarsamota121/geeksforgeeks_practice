// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Function to count number of pairs such that x^y is greater than y^x
// X[], Y[]: input array
// m, n: size of arrays X[] and Y[] respectively
long long count(int x, int Y[], int n, int mY[]) {
    if (x == 0) return 0;

    if (x == 1) return mY[0];

    int *idx = upper_bound(Y, Y + n, x);
    int ans = (Y + n - idx);

    ans += (mY[0] + mY[1]);

    if (x == 2) ans -= (mY[3] + mY[4]);

    if (x == 3) ans += mY[2];

    return ans;
}

long long countPairs(int X[], int Y[], int m, int n) {
    //Your code here
    int mY[5] = {0};
    for (int i = 0; i < n; i++) {
        if (Y[i] < 5) mY[Y[i]]++;
    }

    sort(Y, Y + n);

    int total_pairs = 0;

    for (int i = 0; i < m; i++)
        total_pairs += count(X[i], Y, n, mY);

    return total_pairs;
}

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int M, N;
        cin >> M >> N;
        int i, a[M], b[N];
        for (i = 0; i < M; i++) {
            cin >> a[i];
        }
        for (i = 0; i < N; i++) {
            cin >> b[i];
        }
        cout << countPairs(a, b, M, N) << endl;
    }
}  // } Driver Code Ends