#include<bits/stdc++.h>
using namespace std;
using ll = long long;
typedef struct Node
{
    char val;
    struct Node *left,*right;
}Node;
Node* insert(Node *root,char ch)
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
void inorder(Node *h)
{
    if(h != NULL)
    {
        inorder(h -> left);
        cout<< h -> val<<" ";
        inorder(h -> right);
    }
}
ll height(Node *root)
{
    if(root == NULL) return 0;
    return 1+ max(height(root -> left), height(root -> right));
}
char deepNodes(Node *root, ll level)
{
    if(root == NULL) return '-';
    if(level == 1) return root -> val;
    char ch = deepNodes(root -> left, level-1);
    if(ch != '-') return ch;
    return deepNodes(root -> right, level-1);
}
int main()
{
    Node *root = NULL;
    ll n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        char ch; cin >> ch;
        root = insert(root,ch);
    }
    ll level = height(root);
    cout << deepNodes(root,level);
}