#include<bits/stdc++.h>
using namespace std;
using ll = long long;
typedef struct Node
{
    char val;
    struct Node *left,*right;
}Node;
vector<char> preorder,inorder;
ll pre_idx = 1;
Node* createTree(ll low, ll high)
{
    if(low > high) return NULL;
    if(low == high)
    {
        pre_idx++;
        Node *n = new Node;
        n -> val = inorder[low];
        n -> left = n -> right = NULL;
        return n;
    }
    ll idx;
    for(int i=low;i<=high;i++)
    {
        if(preorder[pre_idx] == inorder[i])
        {   pre_idx++; idx = i; break;}
    }
    Node *n = new Node;
    n -> val = inorder[idx];
    n -> left = createTree(low,idx-1);
    n -> right = createTree(idx+1,high);
    return n;
}
void postorder(Node *root)
{
    if(root)
    {
        postorder(root -> left);
        postorder(root -> right);
        cout<<root -> val<<" ";
    }
}
int main()
{
    ll n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        char x; cin >> x;
        preorder.push_back(x);
    }
    ll idx;
    for(int i=0;i<n;i++)
    {
        char x; cin >> x;
        if(x == preorder[0])
            idx = i;
        inorder.push_back(x);
    }
    Node *root = new Node;
    root -> val = inorder[idx];
    root -> left = createTree(0,idx-1);
    root -> right = createTree(idx+1,n-1);
    postorder(root);
    return 0;
}