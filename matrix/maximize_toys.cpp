#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t{};
    cin >> t;
    while(t--)
    {
        int n{};
        int k{};
        cin >> n >> k;
        int A[n]{0};
        for(auto &a : A)
            cin >> a;
        
        sort(A, A+n);

        int num_toys{};
        for (int i{ 0 }; i < n; i++)
        {
            if (k - A[i] > 0)
            {
                num_toys++;
                k -= A[i];
            }
            else
                break;            
        }
        cout << num_toys << endl;
    }
    return 0;
}