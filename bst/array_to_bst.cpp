#include <bits/stdc++.h>
using namespace std;

struct Node 
{
    int data;
    Node *left;
    Node *right;
};

void Preorder(Node *root)
{
    if (root)
    {
        cout << root->data << ' ';
        Preorder(root->left);
        Preorder(root->right);
    }
}

Node *buildTree(vector<int> &v, int start, int end)
{
    if (start > end)
        return NULL;
    int mid = (start + end) / 2;
    Node *root = new Node;
    root->data = v[mid];
    root->left = buildTree(v, start, mid - 1);
    root->right = buildTree(v, mid + 1, end);
    return root;
}

int main()
{
    int t{};
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            v.push_back(a);
        }

        Node *root = buildTree(v, 0, n-1);
        // cout << "This caused it!\n";
        Preorder(root);
        cout << endl;
    }
    return 0;
}