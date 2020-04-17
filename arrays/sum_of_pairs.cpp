#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t{};
    cin >> t;
    while(t--)
    {
        int n{};
        cin >> n;
        int A[n];
        for(auto &a : A)
            cin >> a;
        
        int sum{ 0 };
        for (int i{ 0 }; i < n; i++)
            for (int j{ 0 }; j < i; j++)
                if (A[i] - A[j] > 1 || A[i] - A[j] < -1)
                    sum += A[i] - A[j];
        
        cout << sum << endl;
    }
    return 0;
}