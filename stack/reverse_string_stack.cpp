// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
void reverse(char *str, int len);
int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {
        char str[10000];
        cin >> str;
        long long int len = strlen(str);
        reverse(str, len);
        cout << str;
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
void reverse(char *str, int len)
{

    // Your code goes here
    int top{};
    char rstr[len+1];
    for (int i = len - 1, j = 0; i > j; i--, j++)
        swap(str[j], str[i]);
}