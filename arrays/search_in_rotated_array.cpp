#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (arr[m] == x)
            return m;

        if (arr[m] < x)
            l = m + 1;

        else
            r = m - 1;
    }
    return -1;
}

int main()
{
    int t{};
    cin >> t;
    while (t--)
    {
        int n{};
        cin >> n;
        int arr[n];
        for (auto &a : arr)
            cin >> a;
        
        int k{};
        cin >> k;
        
        // int pivot_index{0};
        int index{-1};

        for (int i{0}; i<n; i++)
            if (arr[i] == k)
                index = i;
        
        // for (int i{0}; i < n; i++)
        //     if (arr[i+1] < arr[i])
        //         pivot_index = i;

        // index = binarySearch(arr, pivot_index+1, n-1, k);
        // if (index == -1)
        //     index = binarySearch(arr, 0, pivot_index, k);

        cout << index << endl;
    }
    return 0;
}