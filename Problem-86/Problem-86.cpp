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
struct LBST{
    ll sze,max,min,ans;
    bool isBST;
};

LBST largestBST(Node *root)
{
    if(root == NULL)
        return {    0,INT_MIN,INT_MAX,0,true };
    if(root -> left == NULL && root -> right == NULL) return {
        1,root -> data,root -> data,1,true
    };

    LBST left  = largestBST(root -> left);
    LBST right = largestBST(root -> right);

    LBST current;
    current.sze = 1+left.sze+right.sze;

    if(left.isBST && right.isBST && left.max < root -> data && right.min > root -> data)
    {
        current.min =  min(left.min,min(right.min,root -> data));
        current.max = max(right.max,max(left.max,root -> data));

        current.ans = current.sze;
        current.isBST = true;

        return current;
    }

    current.ans = max(left.ans, right.ans);
    current.isBST = false;
    return current;
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
    
    cout << largestBST(root).ans;
    return 0;
}