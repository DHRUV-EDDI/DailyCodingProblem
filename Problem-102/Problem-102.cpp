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
vector<vector<ll>> ans;
void allPossiblePaths(Node *root,vector<ll> cur)
{
    if(root == NULL) return;
    cur.push_back(root -> val);
    if(root -> left == NULL && root -> right == NULL){
        ans.push_back(cur);
        return;
    }
    allPossiblePaths(root -> left, cur);
    allPossiblePaths(root -> right, cur);
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
    allPossiblePaths(root,{});
    for(auto i: ans){
        for(auto j: i)
            cout << j << " ";
        cout << "\n";
    }
    return 0;
}