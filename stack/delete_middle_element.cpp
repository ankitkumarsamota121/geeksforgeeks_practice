// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

stack<int> deleteMid(stack<int> s, int sizeOfStack, int current);

int main() {
    int testcases;
    cin >> testcases;

    while (testcases--) {
        int sizeOfStack;
        cin >> sizeOfStack;

        stack<int> myStack;

        for (int i = 0; i < sizeOfStack; i++) {
            int x;
            cin >> x;
            myStack.push(x);
        }
        if (sizeOfStack == 1) {
            cout << myStack.top();
        } else {
            stack<int> modified = deleteMid(myStack, myStack.size(), 0);

            while (!modified.empty()) {
                cout << modified.top() << " ";
                modified.pop();
            }
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends

//User function Template for C++

//You need to complete this function
stack<int> deleteMid(stack<int> s, int sizeOfStack, int current) {
    //Your code here
    // Base Case
    if (current == floor(sizeOfStack / 2.0)) {
        s.pop();
        return s;
    }

    // Recursive Case
    int a = s.top();
    s.pop();
    s = deleteMid(s, sizeOfStack, current + 1);
    s.push(a);
    return s;
}
