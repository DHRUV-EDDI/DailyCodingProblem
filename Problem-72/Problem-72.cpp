#include<bits/stdc++.h>
using namespace std;
using ll = long long;
typedef struct Node
{
    ll val;
    struct Node *next;
}Node;

Node* insert(Node *head, ll val)
{
    Node *n = new Node;
    n -> val = val;
    n -> next = NULL;

    if(head == NULL)
        head = n;
    else{
        Node *temp = head;
        while(temp -> next != NULL)
            temp = temp -> next;
        temp -> next = n;
    }
    return head;
}

void traverse(Node *head)
{
    Node *temp =  head;
    while(temp != NULL)
    {
        cout<<temp -> val<<" ";
        temp = temp -> next;
    }
}
Node *mergeLists(Node *head1, Node *head2)
{
    if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;
    Node *head = NULL,*temp1 = head1, *temp2 = head2,*cur=NULL;
    while(temp1 && temp2)
    {
        if(temp1 -> val <= temp2 -> val)
        {
            head = insert(head,temp1 -> val);
            temp1 = temp1 -> next;
        }
        else
        {
            head = insert(head,temp2 -> val);
            temp2 = temp2 -> next;
        }
    }
    if(temp1)
    {
        cur = head;
        while(cur -> next)
            cur = cur -> next;
        cur -> next = temp1;
    }
    else if(temp2){
        cur = head;
        while(cur -> next)
            cur = cur -> next;
        cur -> next = temp2;
    }
    return head;
}
int main()
{
    ll k;
    cin >> k;
    Node* arr[k+1];
    for(int i=0;i<k;i++)
    {
        arr[i] = NULL;
        ll n;
        cin >> n;
        for(int j=0;j<n;j++)
        {
            ll val;
            cin >> val;
            arr[i] = insert(arr[i],val);
        }
    }
    if(k == 1)
    {
        traverse(arr[0]);
        return 0;
    }
    Node *head = mergeLists(arr[0],arr[1]);
    for(int i=2;i<k;i++)
        head = mergeLists(head,arr[i]);
    traverse(head);
    return 0;
}