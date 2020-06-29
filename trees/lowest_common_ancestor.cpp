// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};
Node* lca(Node* root, int n1, int n2);
// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // for(string i:ip)
    //     cout<<i<<" ";
    // cout<<endl;
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {
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
        if (currVal != "N") {
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// Function for Inorder Traversal
void printInorder(Node* root) {
    if (!root)
        return;

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int a, b;
        scanf("%d %d ", &a, &b);
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        cout << lca(root, a, b)->data << endl;
    }
    return 0;
}
// } Driver Code Ends

/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

/* If n1 and n2 are present, return pointer
   to LCA. If both are not present, return 
   NULL. Else if left subtree contains any 
   of them return pointer to left.*/

bool findPath(Node* root, vector<Node*>& v, int n) {
    // Base Case
    if (!root) {
        return false;
    }

    if (root->data == n) {
        v.push_back(root);
        return true;
    }

    v.push_back(root);
    bool l = findPath(root->left, v, n);
    bool r = findPath(root->right, v, n);

    if (!l and !r) {
        v.pop_back();
        return false;
    }

    return true;
}

Node* lca(Node* root, int n1, int n2) {
    //Your code here

    vector<Node*> n1_path;
    vector<Node*> n2_path;

    findPath(root, n1_path, n1);
    findPath(root, n2_path, n2);

    if (n1_path.size() == 0 or n2_path.size() == 0) {
        return NULL;
    }

    int len = min(n1_path.size(), n2_path.size());
    Node* ans;

    for (int i = 0; i < len; i++) {
        if (n1_path[i] != n2_path[i]) {
            break;
        }
        ans = n1_path[i];
    }
    return ans;
}