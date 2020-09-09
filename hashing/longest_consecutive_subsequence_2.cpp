// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findLongestConseqSubseq(int arr[], int n);

// Driver program
int main() {
    int t, n, i, a[100001];
    cin >> t;
    while (t--) {
        cin >> n;
        for (i = 0; i < n; i++)
            cin >> a[i];
        cout << findLongestConseqSubseq(a, n) << endl;
    }

    return 0;
}  // } Driver Code Ends

// arr[] : the input array
// N : size of the array arr[]

// return the length of the longest subsequene of consecutive integers
int findLongestConseqSubseq(int arr[], int N) {
    //Your code here
    int freq[100005]{0};
    for (int i = 0; i < N; i++) freq[arr[i]]++;
    int ans = -1;
    int i = 0;
    while (i < 100005) {
        int cnt = 0;
        while (freq[i] != 0) {
            cnt++;
            i++;
        }

        ans = max(ans, cnt);

        while (freq[i] == 0) i++;
    }
    return ans;
}