#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        long long a[n];
        for (long long i = 0; i < n; i++)
            cin >> a[i];

        long long cSum[n]{0};
        long long m = 0;
        cSum[0] = a[0];
        for (long long i = 1; i < n; i++)
        {
            if (a[i] < 0)
                cSum[i] = 0;
            else
            {
                cSum[i] += (a[i] + cSum[i - 1]);
            }
        }

        int left;
        int right;

        for (int i = 0; i < n; i++)
        {
            if (a[i] < 0)
                continue;
            for (int j = i; j < n; j++)
            {
                if (a[j] < 0)
                    continue;
                int sum = cSum[j] - cSum[i - 1];
                if (sum > m)
                {
                    m = sum;
                    left = i;
                    right = j;
                }
            }
        }

        // cout << m << endl;

        for (int i = left; i <= right; i++)
        {
            cout << a[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}