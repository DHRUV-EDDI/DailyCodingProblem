#include<bits/stdc++.h>
using namespace std;
using ll = long long;
typedef struct  Node{
    int val;
    struct Node *next,*prev;
}Node;
Node *insert(Node *head, ll val)
{
    Node *n = new Node;
    n -> val = val;
    n -> next = NULL;
    if(head == NULL) head = n;
    else{
        Node *temp = head;
        while(temp -> next)
            temp = temp -> next;
        temp -> next = n;
    }
    return head;
}
Node *reverse(Node *head)
{
    Node *cur = head,*prev = NULL, *next = NULL;
    while(cur != NULL)
    {
        next = cur -> next;
        cur -> next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}
bool isPalindrome(Node *head, ll n)
{
    ll mid = n/2,i=0;
    Node *frstHalf = head, *secndHalf = NULL;
    while(frstHalf)
    {
        i++;
        if( i == mid) break;
        frstHalf = frstHalf -> next;
    }
    if(n & 1)
    {
        secndHalf = frstHalf -> next -> next;
        frstHalf -> next = NULL;
        frstHalf = head;
    }
    else
    {
        secndHalf = frstHalf -> next;
        frstHalf -> next = NULL;
        frstHalf = head;
    }
    secndHalf = reverse(secndHalf);
    while(frstHalf && secndHalf)
    {
        if(frstHalf -> val != secndHalf -> val)
            return false;
        frstHalf = frstHalf -> next;
        secndHalf = secndHalf -> next;
    }
    return true;
}
int main()
{
    Node *head = NULL;
    ll n;
    cin >> n;
    for(int i=0;i<n;i++){
        ll x; cin >> x;
        head = insert(head,x);
    }
    if(n == 1 || isPalindrome(head,n))
        cout << "True\n";
    else
        cout << "False\n";
    return 0;
}