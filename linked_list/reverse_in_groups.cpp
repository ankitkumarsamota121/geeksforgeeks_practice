// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct node *reverse(struct node *head, int k);

struct node
{
    int data;
    struct node *next;

    node(int x)
    {
        data = x;
        next = NULL;
    }
};

/* UTILITY FUNCTIONS */
/* Function to push a node */

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
int main(void)
{
    /* Start with the empty list */

    int t;
    cin >> t;

    while (t--)
    {
        struct node *head = NULL;
        struct node *temp = NULL;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            int value;
            cin >> value;
            if (i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }

        int k;
        cin >> k;
        head = reverse(head, k);

        printList(head);
    }

    return (0);
}

// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

struct node *reverse(struct node *head, int k)
{
    // Complete this method
    node *p = head;
    node *q = NULL;
    node *r = NULL;
    node *l = NULL;
    node *begin = NULL;
    for (int i = 0; i < k && p; i++)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    l = head;
    head->next = p;
    head = q;

    // cout << p->data << endl;
    // cout << q->data << endl;
    // cout << r->data << endl;

    while (p)
    {
        begin = p;
        r = NULL;
        q = NULL;
        for (int i = 0; i < k && p; i++)
        {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }
        l->next = q;
        l = begin;
        begin->next = p;
        // cout << begin->next << endl;
    }

    return head;
}
