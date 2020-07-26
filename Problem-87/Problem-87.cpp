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
ll ans = INT_MIN;
ll maxiumSum(Node *root)
{
    if(root == NULL) 
        return INT_MIN;
    if(root -> left == NULL && root -> right == NULL){
        ans = max(ans,root -> data);
        return root -> data;
    }
    ll leftValue  = maxiumSum(root -> left)  + root -> data;
    ll rightValue = maxiumSum(root -> right) + root -> data;

    ll frstPath = max(root -> data, max(leftValue,rightValue));
    ans = max(ans, max(frstPath, (leftValue + rightValue - root -> data)));

    return frstPath;
}
int main()
{
    ll n;
    cin >> n;
    Node *root = NULL;
    for(int i=0;i<n;i++){
        ll val; 
        cin >> val;
        root = insert(root,val);
    }

    maxiumSum(root);
    cout << ans << "\n";
    return 0;
}