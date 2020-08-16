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
Node* findLCA(Node *root,ll a, ll b)
{
    if(root == NULL) return NULL;
    if(root -> val == a || root -> val == b) return root;

    Node *left = findLCA(root -> left,a,b);
    Node *right = findLCA(root -> right,a,b);
    if(left && right) return root;

    return (left) ? left : right;
}
int main()
{
    ll n;
    cin >> n;
    Node *root = NULL;
    for(int i=0;i<n;i++){
        ll x; cin >> x;
        root = insert(root,x);
    }
    ll a,b;
    cin >> a >> b;
    cout << findLCA(root,a,b) -> val;
    return 0;
}