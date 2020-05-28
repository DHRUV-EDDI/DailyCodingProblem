#include<bits/stdc++.h>
using namespace std;
using ll = long long;
typedef struct Node
{
    struct Node *right,*left;
    ll val;
}Node;
Node* insert(Node *root,ll val)
{
    if(root == NULL)
    {
        Node *n = new Node;
        n -> val = val;
        n -> left = n -> right = NULL;
        return n;
    }
    else if(val < root -> val )
        root -> left = insert(root-> left,val);
    else
        root -> right = insert(root -> right,val);
    return root;
}
/*
    We can solve this using two methods:
      1) Using Revese Inorder traversal.
      2) If rightmost node is leaf then its parent will be the second max element.
         Otherwise, predecessor of the rightmost node will be the second max element
*/
void reverseInorder(Node *root,ll &c)
{
    if(root == NULL || c >= 2)
        return;
    reverseInorder(root -> right,c);
    c++;
    if(c == 2)
    {
        cout<<root -> val<<" ";
        return;
    }
    reverseInorder(root ->left,c);
}
Node* getMax(Node *root)
{
    Node *cur = root;
    while(cur -> right)
        cur = cur -> right;
    return cur;
}
Node *predecessor(Node *root,Node *maxNode)
{
    if(maxNode -> left != NULL)
    {
        //Predecessor
        Node *cur = maxNode -> left;
        while(cur -> right)
            cur = cur -> right;
        return cur;
    }
    else
    {
        // Finding the parent of Max element
        Node *cur = root,*parent=NULL;
        while(cur -> val != maxNode -> val)
        {
            parent = cur;
            cur = cur -> right;
        }
        return parent;
    }
}
int main()
{
    Node *root = NULL;
    ll n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        ll val; cin >> val;
        root = insert(root,val);
    }
    // METHOD-1
    ll c = 0;
    reverseInorder(root,c);
    // METHOD-2
    Node *maxNode = getMax(root);
    Node *secMax = predecessor(root,maxNode);
    cout<<secMax -> val;
    return 0;
}