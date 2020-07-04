#include<bits/stdc++.h>
using namespace std;
using ll = long long;
typedef struct Node
{
    ll val;
    struct Node *next;
}Node;
Node* insert(Node *head,ll val)
{
    Node *n = new Node;
    n -> val = val;
    n -> next = NULL;
    if(head == NULL)
        head = n; 
    else
    {
        Node *temp = head;
        while(temp -> next != NULL)
            temp = temp -> next;
        temp -> next = n;
    }
    return head;
}
Node *reverse(Node *head)
{
    Node *prev = NULL, *cur = head, *n = NULL;
    while(cur != NULL)
    {
        n = cur -> next;
        cur -> next = prev;
        prev = cur;
        cur = n;
    }
    return prev;
}
int main()
{
    ll n;
    cin >> n;
    Node *head = NULL;
    for(int i=0;i<n;i++)
    {
        ll val; cin >> val;
        head = insert(head,val);
    }
    head = reverse(head);
    while(head)
    {
        cout<<head -> val<<" ";
        head = head -> next;
    }
    return 0;
}