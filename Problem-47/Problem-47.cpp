#include<bits/stdc++.h>
using namespace std;
using ll = long long;
typedef struct Node
{
    char val;
    struct Node *left,*right;
}Node;
Node* insert(Node *root,char x)
{
    Node *n = new Node;
    n -> val = x;
    n -> left = n -> right = NULL;
    if(root == NULL)
        return n;
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node *r = q.front();
        q.pop();
        if( r -> left == NULL)
        {
            r -> left = n;
            break;
        }
        if(r -> right == NULL)
        {
            r -> right = n;
            break;
        }
        q.push(r -> left);
        q.push(r -> right);
    }
    return root;
}
void inorder(Node *root)
{
    if(root)
    {
        inorder(root -> left);
        cout<<root -> val<<" ";
        inorder(root -> right);
    }
}
ll evaluate(ll a, ll b, char x)
{
    switch(x)
    {
        case '*': return a*b;
        case '+': return a+b;
        case '-': return a-b;
        case '/': return a/b;
        case '%': return a%b;
    }
}
ll evaluateExpression(Node *root)
{
    if(root == NULL) return 0;
    if(root -> left == NULL && root -> right == NULL)
        return (root -> val - '0');
    ll leftPart = evaluateExpression(root -> left);
    ll righPart = evaluateExpression(root -> right);
    return evaluate(leftPart,righPart,root -> val);
}
int main()
{
    ll n;
    cin >> n;
    Node *root = NULL;
    for(int i=0;i<n;i++)
    {
        char x; cin >> x;
        root = insert(root,x);
    }
    cout << evaluateExpression(root);
    return 0;
}