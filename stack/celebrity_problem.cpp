// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 501

int getId(int M[MAX][MAX], int n);

int main() {
    int T;
    cin >> T;
    int M[MAX][MAX];
    while (T--) {
        int N;
        cin >> N;
        memset(M, 0, sizeof M);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> M[i][j];
            }
        }
        cout << getId(M, N) << endl;
    }
}

// } Driver Code Ends

// The task is to complete this function

// M[][]: input matrix
// n: size of matrix (n*n)
int getId(int M[MAX][MAX], int n) {
    //Your code here
    stack<int> s;
    for (int i = 0; i < n; i++) {
        s.push(i);
    }

    while (s.size() > 1) {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        if (M[a][b] == 1) {
            s.push(b);
        } else {
            s.push(a);
        }
    }

    bool flag = true;
    int c = s.top();

    // cout << c << endl;

    for (int i = 0; i < n; i++) {
        if (c != i && (M[c][i] != 0 || M[i][c] == 0)) {
            flag = false;
            break;
        }
    }

    return (flag ? c : -1);
}