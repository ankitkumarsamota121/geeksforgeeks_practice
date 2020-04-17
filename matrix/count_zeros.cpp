// { Driver Code Starts
#include <iostream>
using namespace std;
#define MAX 1000
int countZeroes(int A[MAX][MAX], int N);

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int A[MAX][MAX];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> A[i][j];
        cout << countZeroes(A, n) << endl;
    }
    return 0;
} // } Driver Code Ends
/*you are required to complete this method*/
int countZeroes(int A[MAX][MAX], int N)
{
    int count{ 0 };
    for(int i{ 0 }; i < N; i++)
        for(int j{ 0 }; j < N; j++)
            if (!A[i][j]) count++;
    
    return count;
}
