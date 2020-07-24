// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

int largestBst(Node* root);

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

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

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
            currNode->left = new Node(stoi(currVal));

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
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root1 = buildTree(s);

        //getline(cin, s);
        // int k = stoi(s);
        // getline(cin, s);

        cout << largestBst(root1);
        cout << endl;
        //cout<<"~"<<endl;
    }
    return 0;
}  // } Driver Code Ends

/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

int predecessor(Node* root) {
    if (!root)
        return INT_MIN;

    Node* curr = root->left;
    while (curr && curr->right)
        curr = curr->right;

    if (curr) return curr->data;
    return INT_MIN;
}

int successor(Node* root) {
    if (!root) return INT_MAX;
    Node* curr = root->right;
    while (curr && curr->left)
        curr = curr->left;

    if (curr) return curr->data;
    return INT_MAX;
}

int util(Node* root, int& res) {
    if (!root) {
        return 0;
    }

    if (!root->left && !root->right) {
        return 1;
    }

    int left = util(root->left, res);
    int right = util(root->right, res);
    if (left != -1 && right != -1) {
        int pred = predecessor(root);
        int succ = successor(root);
        if (pred < root->data && succ > root->data) {
            res = max(res, left + right + 1);
            return left + right + 1;
        }
    }
    return -1;
}

/*You are required to complete this method */
// Return the size of the largest sub-tree which is also a BST
int largestBst(Node* root) {
    //Your code here
    int res = 1;
    util(root, res);
    return res;
}