// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Utility function to create a new Tree Node
Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

bool isPairPresent(Node *root, int k);

// Function to Build Tree
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int main()
{

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);

        getline(cin, s);
        int k = stoi(s);
        //getline(cin, s);

        cout << isPairPresent(root, k) << endl;
        //cout<<"~"<<endl;
    }
    return 0;
}
// } Driver Code Ends
/*Complete the function below
Node is as follows
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

void Inorder(Node *root, vector<int> &v)
{
    if (root)
    {
        Inorder(root->left, v);
        v.push_back(root->data);
        Inorder(root->right, v);
    }
}

bool isPresent(Node *root, int x)
{
    if (!root)
        return false;
    if (root->data == x)
        return true;
    else if (x < root->data)
        return isPresent(root->left, x);
    else
        return isPresent(root->right, x);
}

bool isPairPresent(struct Node *root, int target)
{
    //add code here.
    vector<int> v;
    Inorder(root, v);

    for (int i = 0; v[i] <= root->data; i++)
    {
        if (isPresent(root, (target-v[i])) && v[i] != target - v[i])
            return true;
    }
    return false;
}