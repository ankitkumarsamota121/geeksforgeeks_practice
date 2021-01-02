// { Driver Code Starts
// C++ program to remove recurring digits from
// a given number
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

vector<int> leaders(int arr[], int n) {
    // code here
    vector<int> v;
    int temp[n + 1];
    temp[n] = 0;
    for (int j = n - 1; j >= 0; j--) {
        if (arr[j] <= temp[j + 1]) {
            temp[j] = temp[j + 1];
        } else {
            temp[j] = arr[j];
        }
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] == temp[i]) {
            v.push_back(arr[i]);
        }
    }

    return v;
}

// { Driver Code Starts.

int main() {
    long long t;
    cin >> t;  //testcases
    while (t--) {
        long long n;
        cin >> n;  //total size of array

        int a[n];

        //inserting elements in the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }

        //calling leaders() function
        vector<int> v = leaders(a, n);

        //printing elements of the vector
        for (auto it = v.begin(); it != v.end(); it++) {
            cout << *it << " ";
        }

        cout << endl;
    }
}
// } Driver Code Ends