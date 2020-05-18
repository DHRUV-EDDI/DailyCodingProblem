#include<bits/stdc++.h>
using namespace std;
using ll = long long;
typedef struct Node
{
    struct Node *next;
    ll data;
}Node;
Node* insert(Node *head, ll val)
{
    Node *n = new Node;
    n -> next = NULL;
    n -> data = val;
    if(head == NULL)
    {
        head = n;
        return n;
    }
    else
    {
        Node *temp=head;
        while(temp -> next)
            temp = temp -> next;
        temp -> next = n;
        return head;
    }
}
Node* KthNode(Node *h,ll k)
{
    Node *cur=h,*back=h;
    ll i=0;
    while( i < k && back != NULL)
    {
        back = back -> next;
        i++;
    }
    Node *prev = NULL;
    while(back != NULL)
    {
        back = back -> next;
        prev = cur;
        cur = cur -> next;
    }
    if(prev == NULL)
        return h -> next;
    prev -> next = cur -> next;
    return h;
}
int main()
{
    ll n;
    cin>>n;
    Node *head = NULL;
    for(int i=0;i<n;i++)
    {
        ll x; cin>>x;
        head = insert(head,x);
    }
    ll k;
    cin>>k;
    head = KthNode(head,k);
    Node *temp = head;
    while(temp)
    {
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    return 0;
}