// { Driver Code Starts
#include <bits/stdc++.h>

#define N 105
using namespace std;

int *mergeKArrays(int arr[][N], int k);

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        int arr[N][N];
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                cin >> arr[i][j];
            }
        }
        int *output = mergeKArrays(arr, k);
        printArray(output, k * k);
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends

// your task is tocomplete this function
// function should return an pointer to output array int*
// of size k*k

using pii = pair<int, int>;

int *mergeKArrays(int arr[][N], int k) {
    //code here
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
    int *out = new int[10005];

    for (int i = 0; i < k; i++) {
        pq.push({arr[i][0], {i, 0}});
    }

    int r = 0;
    int i, j;
    while (!pq.empty()) {
        int x = pq.top().first;
        i = pq.top().second.first;
        j = pq.top().second.second;
        j++;
        pq.pop();

        if (j < k) {
            pq.push({arr[i][j], {i, j}});
        }

        out[r++] = x;
    }

    return out;
}