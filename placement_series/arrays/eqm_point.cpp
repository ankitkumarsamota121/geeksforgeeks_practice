// { Driver Code Starts
#include <iostream>
using namespace std;

// Position this line where user code will be pasted.

int equilibriumPoint(long long a[], int n);

int main() {
    long long t;

    //taking testcases
    cin >> t;

    while (t--) {
        long long n;

        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }

        //calling equilibriumPoint() function
        cout << equilibriumPoint(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends

// Function to find equilibrium point
// a: input array
// n: size of array
int equilibriumPoint(long long a[], int n) {
    // Your code here
    long long sum = 0;
    for (int i = 0; i < n; i++) sum += a[i];

    long long left = 0;
    long long right = sum;
    int ans = -1;
    for (int j = 0; j < n; j++) {
        right -= a[j];
        if (left == right) {
            ans = j + 1;
            break;
        }
        left += a[j];
    }

    return ans;
}