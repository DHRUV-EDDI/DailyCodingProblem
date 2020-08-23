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
ll minimumSumLevel(Node *root){
    if(root == NULL) return -1;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    ll ans = INT_MAX,i=1,level=-1;
    vector<ll> v;
    while(!q.empty()){
        Node *front = q.front();
        q.pop();
        if(front == NULL){
            ll sum = accumulate(v.begin(),v.end(),0);
            if(ans > sum){
                ans = sum;
                level = i;
            }
            i++;
            v.clear();
            if(!q.empty())
                q.push(NULL);
            continue;
        }
        v.push_back(front -> val);
        if(front -> left) q.push(front -> left);
        if(front -> right) q.push(front -> right);
    }
    return level;
}
void inorder(Node *root)
{
    if(root)
    {
        inorder(root -> left);
        cout << root -> val<<" ";
        inorder(root -> right);
    }
}
int main()
{
    ll n;
    Node *root = NULL;
    cin >> n;
    for(int i=0;i<n;i++){
        ll x; cin >> x;
        root = insert(root,x);
    }
    cout << minimumSumLevel(root)<<"\n";
    return 0;
}