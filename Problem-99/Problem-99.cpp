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
ll height(Node *root)
{
    if(root == NULL) return 0;
    return 1 + max(height(root -> left), height(root -> right));
}
void levelOrder(Node *root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    bool corner = false;
    vector<ll> v;
    while(!q.empty())
    {
        Node *x = q.front();
        q.pop();
        if( x == NULL){
            for(auto i: v)
                cout << i << " ";
            cout << "\n";
            v.clear();
            if(!corner)
                q.push(NULL);
            corner = true;
        }
        else{
            corner = false;
            v.push_back(x -> val);
            if(x -> left) q.push(x -> left);
            if(x -> right) q.push(x -> right);
        }
    }
}
int main()
{
    Node *root = NULL;
    ll n;
    cin >> n;
    for(int i=0;i<n;i++){
        ll x; cin >> x;
        root = insert(root,x);
    }
    levelOrder(root);
    return 0;
}