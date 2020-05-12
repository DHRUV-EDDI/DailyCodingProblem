#include<bits/stdc++.h>
using namespace std;
using ll = long long;
typedef struct Node
{
    ll val;
    struct Node *next;
}Node;
ll m,n;
Node* insert(ll val,Node* head)
{
    Node* n = new Node;
    n -> val = val;
    n -> next = NULL;
    if(head == NULL)
        head = n;
    else
    {
        Node *temp = head;
        while(temp -> next)
            temp = temp -> next;
        temp -> next = n;
    }
    return head;
}
int findIntersectionPoint(Node *head1, Node *head2)
{
    ll frst_count=m,scnd_count=n;
    Node *h1 = head1,*h2 = head2;
    while( frst_count > scnd_count)
    {
        h1 = h1 -> next;
        frst_count--;
    }
    while( scnd_count > frst_count)
    {
        h2 = h2 -> next;
        scnd_count--;
    }
    while( h1 && h2)
    {
        if(h1 -> val == h2 -> val)
            return h1 -> val;
        h1 = h1 -> next;
        h2 = h2 -> next;
    }
    return INT_MIN;
}
void printList(Node *h)
{
    while(h)
    {
        cout<<h -> val<<" ";
        h = h -> next;
    }
    cout<<"\n";
}
int main()
{
    cin>>m>>n;
    Node *head1=NULL,*head2=NULL;
    for(int i=0;i<m;i++)
    {
        ll x; cin>> x;
        head1 = insert(x,head1);
    }
    for(int i=0;i<n;i++)
    {
        ll x; cin>> x;
        head2 = insert(x,head2);
    }
    int intersect = findIntersectionPoint(head1,head2);
    if( intersect == INT_MIN) 
        cout<<"No Intersection Point\n";
    else
        cout<<intersect<<"\n";
    return 0;
}