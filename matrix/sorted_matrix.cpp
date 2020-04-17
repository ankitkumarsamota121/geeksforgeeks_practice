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
        int M[n*n]{0};
        for(auto &a : M)
            cin >> a;
        
        sort(M, M+n*n);

        for(auto &a : M)
            cout << a << ' ';
            
        cout << endl;
    }
    return 0;
}