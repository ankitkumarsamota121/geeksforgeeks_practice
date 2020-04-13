#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t{};
    cin >> t;
    while (t--)
    {
        int n{};
        cin >> n;
        int A[n];
        int B[n];
        int C[n+n];
        for (auto &a : A)
            cin >> a;

        for (auto &b : B)
            cin >> b;

        int i{};
        int j{};
        int k{};

        while (i < n && j < n)
        {   
            if (A[i] <= B[j])
                C[k++] = A[i++];
            else
                C[k++] = B[j++];
        }
        for (; i<n; i++)
            C[k++] = A[i++];
        for (; j<n; j++)
            C[k++] = B[j++];

        cout << C[n] + C[n-1] << endl;

    }
    return 0;
}