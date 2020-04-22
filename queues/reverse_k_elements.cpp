// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
#define ll long long
queue<ll> modifyQueue(queue<ll> q, int k);
int main()
{
    ll t;
    cin >> t;
    while (t-- > 0)
    {
        ll n, k;
        cin >> n >> k;
        queue<ll> q;
        while (n-- > 0)
        {
            ll a;
            cin >> a;
            q.push(a);
        }
        queue<ll> ans = modifyQueue(q, k);
        while (!ans.empty())
        {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
} // } Driver Code Ends
//User function Template for C++

queue<ll> modifyQueue(queue<ll> q, int k)
{
    //add code here.
    stack<ll> st;
    for (int i = 0; i < k; i++)
    {
        st.push(q.front());
        q.pop();
    }

    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }

    int x;
    for (int i = 0; i < q.size() - k; i++)
    {
        x = q.front();
        q.pop();
        q.push(x);
    }
    
    return q;
}