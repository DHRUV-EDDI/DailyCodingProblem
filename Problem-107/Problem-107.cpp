#include<bits/stdc++.h>
using namespace std;
using ll = long long;
typedef struct Node{
    ll val;
    struct Node *left,*right;
}Node;
Node *insert(Node *root,ll val)
{
    Node *n = new Node;
    n -> val = val;
    n -> left = n -> right = NULL;
    if(root == NULL) return root = n;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){

        Node *temp = q.front();
        q.pop();

        if(temp -> left == NULL){
            temp -> left = n;
            break;
        }
        if(temp -> right == NULL){
            temp -> right = n;
            break;
        }
        q.push(temp -> left);
        q.push(temp -> right);
    }
    return root;
}
bool isSame(Node *a, Node *b)
{
    if(!a && !b) return true;
    if(!a || !b) return false;

    return (a -> val == b -> val &&  // If root matches 
            isSame(a -> left, b-> left) && // Check Left subtree 
            isSame(a -> right, b -> right)); // Check Right subtree
}
bool isSubtree(Node *root, Node *subroot){
    if(subroot == NULL) return true;
    if(root == NULL) return false;

    if(isSame(root,subroot)) return true; // Check current tree is a subtroot.

    return isSubtree(root -> left, subroot)  // Check whether left subtree is subroot
        || isSubtree(root -> right, subroot); // Check whether right subtree is subroot
}
int main()
{
    ll n,m;
    cin >> n >> m;
    Node *root = NULL, *subroot = NULL;
    for(int i=0;i<n;i++){
        ll x; cin >> x;
        root = insert(root,x);
    }
    for(int i=0;i<m;i++){
        ll x; cin >> x;
        subroot = insert(subroot,x);
    }
    if(isSubtree(root,subroot))
        cout << "True\n";
    else
        cout << "False\n";
    return 0;
}