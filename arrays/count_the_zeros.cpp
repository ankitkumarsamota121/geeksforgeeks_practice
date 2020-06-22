#include <bits/stdc++.h>
using namespace std;

#define FOREACH(i, c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define FOR(i, a, n) for (register int i = (a); i < (int)(n); ++i)
#define FORE(i, a, n) for (i = (a); i < (int)(n); ++i)
#define Size(n) ((int)(n).size())
#define all(n) (n).begin(), (n).end()

#define ll long long
#define pb push_back
#define error(x) cout << #x << " = " << (x) << endl;
#define ull unsigned long long
#define F first
#define S second
#define mk make_pair
#define mod 1000000007 // 10e9 + 7

#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>

ll mpow(ll base, ll exp)
{
    ll res = 1;
    while (exp > 0)
    {
        if (exp % 2)
            res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res % mod;
}

int find(int A[], int l, int r, int n)
{
    if (l > r) return (n - r - 1);
    int mid = (l + r) / 2;
    if (A[mid] == 1)
        return find(A, mid + 1, r, n);
    else
        return find(A, l, mid - 1, n);
}

int main()
{
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int A[n];
        FOR(i, 0, n) cin >> A[i];
        cout << find(A, 0, n-1, n) << endl;
    }
    return 0;
}