// { Driver Code Starts
#include <bits/stdc++.h>
#define MAX 20
using namespace std;

struct Node
{
    int data;
    Node *right, *down;

    Node(int x)
    {
        data = x;
        right = NULL;
        down = NULL;
    }
};

void display(Node *head)
{
    Node *Rp;
    Node *Dp = head;
    while (Dp)
    {
        Rp = Dp;
        while (Rp)
        {
            cout << Rp->data << " ";
            Rp = Rp->right;
        }

        Dp = Dp->down;
    }
}

Node *constructLinkedMatrix(int mat[MAX][MAX], int n);

// driver program
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int mat[MAX][MAX];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> mat[i][j];
        Node *head = constructLinkedMatrix(mat, n);
        if (!head)
            cout << "-1";
        else
            display(head);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends

/*structure of the node of the linked list is as

struct Node
{
	int data;
	Node* right, *down;
	
	Node(int x){
	    data = x;
	    right = NULL;
	    down = NULL;
	}
};
*/
// n is the size of the matrix
// function must return the pointer to the first element
// of the in linked list i.e. that should be the element at arr[0][0]
Node *constructLinkedMatrix(int mat[MAX][MAX], int n)
{
    // code here
    Node *head = NULL;
    Node *p = NULL;
    Node *q = NULL;
    Node *start = NULL;
    Node *t = NULL;

    for (int row = 0; row < n; ++row){
        q = start;
        for (int col = 0; col < n; ++col){
            t = new Node(mat[row][col]);
            if (head == NULL){
                head = t;
                p = head;
                start = head;
            }
            else if (col == 0){
                p = t;
                if (q){
                    q->down = t;
                    q = q->right;
                }
            }
            else {
                p->right = t;
                p = p->right;
                if (q){
                    q->down = t;
                    q = q->right;
                }
            }
        }
        p = NULL;
        q = start;
        if (start->down) start = start->down;
    }
    return head;
}
