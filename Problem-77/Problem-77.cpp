#include<bits/stdc++.h>
using namespace std;
using ll = long long;
typedef struct Node
{
    ll val;
    struct Node *left,*right;
}Node;
Node* insert(Node *root,ll ch)
{
    if(root == NULL)
    {
        Node *n = new Node;
        n -> val = ch;
        n -> left = n -> right = NULL;
        return n;
    }
    else if( root -> val < ch)
        root -> right = insert(root -> right,ch);
    else if( root -> val > ch)
        root -> left = insert(root -> left,ch);
    return root;
}
void mirrorTree(Node *root)
{
    if(root)
    {
        mirrorTree(root -> left);
        mirrorTree(root -> right);
        Node *temp = root -> left;
        root -> left = root -> right;
        root -> right = temp;
    }
}
void inorder(Node *root)
{
    if(root)
    {
        inorder(root -> left);
        cout << root -> val<<" ";
        inorder(root -> right);
    }
}
int main()
{
    ll n;
    cin >> n;
    Node *root = NULL;
    for(int i=0;i<n;i++)
    {
        ll x; cin >> x;
        root = insert(root,x);
    }
    mirrorTree(root);
    inorder(root);
    return 0;
}
