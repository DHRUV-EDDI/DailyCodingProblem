#include<bits/stdc++.h>
using namespace std;
using ll = long long;
typedef struct Node
{
    int data;
    struct Node *left,*right;
}Node;
Node* insert(Node *root,char val)
{
    if(root == NULL)
    {
        Node *n = new Node;
        n -> data = val;
        n -> left = n -> right = NULL;
        root = n;
        return root;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if(temp -> left == NULL)
        {
            Node *n = new Node;
            n -> data = val;
            n -> left = n -> right = NULL;
            temp -> left = n;
            break;
        }
        else
            q.push(temp -> left);
        
        if(temp -> right == NULL)
        {
            Node *n = new Node;
            n -> data = val;
            n -> left = n -> right = NULL;
            temp -> right = n;
            break;
        }
        else
            q.push(temp -> right);
    }
    return root;
}
int ans=0;
bool univalTrees(Node *root)
{
    if(root == NULL)
        return true;
    if(root -> left == NULL && root -> right == NULL)
    {
        ans++;
        return true;
    }
    bool lvalue = univalTrees(root -> left);
    bool rvalue = univalTrees(root -> right);
    if(lvalue && rvalue)
    {
        bool cleft=true,cright=true;
        if(root -> left != NULL && root ->left -> data != root -> data) cleft = false;
        if(root -> right != NULL && root ->right -> data != root -> data) cright = false;
        if(cleft && cright)
        {
            ans++;
            return true;
        }
    }
    return false;
}
int main()
{
    Node *root = NULL;
    ll n;
    cin>> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        ll x; cin>> x;
        root = insert(root,x);
    }
    univalTrees(root);
    cout<<ans<<"\n";
    return 0;
}