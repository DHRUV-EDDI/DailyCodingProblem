#include<bits/stdc++.h>
using namespace std;
using ll = long long;
struct Node
{
    ll data;
    struct Node *left,*right;
};
typedef struct Node Node;
Node* insert(Node *root, ll val)
{
    Node *n = new Node;
    n -> data = val;
    n -> left = n -> right = NULL;
    if(root == NULL)
        return n;
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if(!temp  -> left)
        {
            temp -> left = n;
            break;
        }
        if(!temp -> right)
        {
            temp -> right = n;
            break;
        }
        q.push(temp -> left);
        q.push(temp -> right);
    }
    return root;
}
bool isBST(Node *root, ll mn, ll mx)
{
    if(root == NULL) return true; 
    if( root -> data < mn || root -> data > mx)
        return false;
    return isBST(root -> left,mn,root -> data -1) && 
           isBST(root -> right,root -> data + 1, mx);
}
int main()
{
    ll n;
    cin >> n;
    Node *root = NULL;
    for(int i=0;i<n;i++)
    {
        ll val; cin >> val;
        root = insert(root,val);
    }
    cout << (isBST(root,INT_MIN,INT_MAX) ? "true": "false");
    return 0;
}