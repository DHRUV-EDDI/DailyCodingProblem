#include<bits/stdc++.h>
using namespace std;
using ll = long long;
typedef struct node
{
    ll value;
    node *both;
}Node;

Node *head = NULL,*cur = NULL;
/*
 uintptr_t is an unsigned integer type capable of holding a pointer. 
=> Reason:
        A common reason to want an integer type that can hold an architecture's pointer type 
        is to perform integer-specific operations on a pointer,or to obscure the type of a 
        pointer by providing it as an integer "handle".
*/
void add(ll x)
{
    Node *n = new Node;
    n -> value = x;
    n -> both = NULL;    
    if(head == NULL)
    {
        head = n;
        cur = head;
    }
    else
    {
        cur -> both = (Node*)( (uintptr_t)(cur -> both) ^ (uintptr_t)n);
        n -> both = cur;
        cur = n; 
    }
    
}
void traverse(Node *h)
{
    Node *prev=NULL,*temp = h,*res;

    while(temp != NULL)
    {
        cout<<temp -> value;
        prev = (Node*)((uintptr_t)(temp -> both) ^ (uintptr_t)(prev));
        res = temp;
        temp = prev;
        prev = res;
        if(temp != NULL)
            cout<<"->";
    }
    cout<<"\n";
}
Node* get(int index)
{
    Node *temp = head,*prev=NULL,*res;
    int i=1;
    while(temp != NULL && i < index)
    {
        prev = (Node*)((uintptr_t)(temp -> both) ^ (uintptr_t)(prev));
        res = temp;
        temp = prev;
        prev = res;
        i++;
    }
    return temp;
}
int main()
{
    ll n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        ll x; cin >> x;
        add(x);
    }
    cout<<"Traversing from left to right : ";
    traverse(head);
    cout<<"Traversing from right to left : ";
    traverse(cur);
    int index;
    cin>>index;
    Node *t = get(index);
    if(t)
    {
        cout<<"Element at "<<index<<" position : ";
        cout<<t-> value;
    }
    else
        cout<<"Invalid position.";
    return 0;
}