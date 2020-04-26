// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        key = x;
        left = NULL;
        right = NULL;
    }
};

void insert(Node **tree, int val)
{
    Node *temp = NULL;
    if (!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if (val < (*tree)->key)
    {
        insert(&(*tree)->left, val);
    }
    else if (val > (*tree)->key)
    {
        insert(&(*tree)->right, val);
    }
}

int mini = INT_MAX;
int findMaxForN(Node *root, int N, int size);

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        Node *root = NULL;
        int n, k;
        cin >> n;
        mini = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            cin >> k;
            insert(&root, k);
        }
        int s;
        cin >> s;

        cout << findMaxForN(root, s, n) << endl;
    }
    return 0;
} // } Driver Code Ends
//User function Template for C++
/*
Structure of the Node of the BST is as
struct Node {
	int key;
	Node* left, *right;
};
*/
/*
   'N' is the element 
   'size' is the total element in BST
  */
int findMaxForN(Node *root, int N, int size)
{
    if (!root)
        return -1;
    if (root->key == N)
        return N;

    else if (root->key < N)
    {
        int k = findMaxForN(root->right, N, size);
        if (k == -1)
            return root->key;
        else
            return k;
    }
    
    else
        return findMaxForN(root->left, N, size);
}