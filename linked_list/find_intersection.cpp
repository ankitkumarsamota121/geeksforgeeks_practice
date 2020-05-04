// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

void printList(struct node *node)
{
    while (node != NULL)
    {
        cout << node->data << ' ';
        node = node->next;
    }
    printf("\n");
}

void push(struct node **head_ref, int new_data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

struct node *findIntersection(struct node *head1, struct node *head2);

int main()
{
    long test;
    cin >> test;
    while (test--)
    {
        struct node *a = NULL;
        struct node *b = NULL;
        int n, m, tmp;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            push(&a, tmp);
        }
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> tmp;
            push(&b, tmp);
        }
        printList(findIntersection(a, b));
    }
    return 0;
}
// } Driver Code Ends

/*
structure of the node is as
struct node
{
	int data;
	struct node* next;
};
*/
struct node *findIntersection(struct node *head1, struct node *head2)
{
    // code here
    set<int> ll_1;
    node *p = head1;
    while (p){
        ll_1.insert(p->data);
        p = p->next;
    }

    set<int> ll_2;
    node *q = head2;
    while (q){
        ll_2.insert(q->data);
        q = q->next;
    }

    node *head = NULL;
    node *t = head;
    node *temp = NULL;
    // cout << "Yahan tak aaya!!\n";
    for(auto &a : ll_1){
        if (ll_2.find(a) != ll_2.end()){
            temp = new node;
            temp->data = a;
            temp->next = NULL;
            if (head == NULL){
                head = temp;
                t = head;
            }
            else{
                t->next = temp;
                t = t->next;
            }
        }
    }

    t = head;

    return head;
}
