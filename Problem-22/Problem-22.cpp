#include<bits/stdc++.h>
using namespace std;
using ll = long long;
typedef struct Node
{
    struct Node *leftChild,*Parent,*rightChild;
    bool isLocked;
    ll val,lockedDescendants;
}Node;
Node *root=NULL;
map<ll,Node*> mp;
Node* insert(ll val)
{
    Node *n = new Node;
    n -> leftChild = n -> Parent = n -> rightChild =  NULL;
    n -> isLocked = false;
    n -> val = val;
    if(root == NULL)
    {
        n -> lockedDescendants = 0;
        root = n;
        mp[val] = root;
        return root;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if(temp -> leftChild == NULL)
        {
            n -> Parent = temp;
            temp -> leftChild = n;
            n -> lockedDescendants = 0;
            mp[val] = n;
            break;
        }
        else
            q.push(temp -> leftChild);
        if(temp -> rightChild == NULL)
        {
            n -> Parent = temp;
            temp -> rightChild = n;
            n -> lockedDescendants = 0;
            mp[val] = n;
            break;
        }
        else
            q.push(temp -> rightChild);
    }
    return root;
}
bool isLocked(Node *t)
{
    return t -> isLocked;
}
void inorder(Node *t)
{
    if(t && !isLocked(t))
    {
        inorder(t -> leftChild);
        cout<<t -> val<<" ";
        inorder(t -> rightChild);
    }
}
bool canUnlockorLock(Node *n)
{
    if(n -> lockedDescendants > 0)
        return false;
    Node *temp = n -> Parent;
    while(temp)
    {
        if(temp -> isLocked)
            return false;
        temp = temp -> Parent;
    }
    return true;
}
bool Lock(Node *n)
{
    if(!isLocked(n) && canUnlockorLock(n))
    {
        Node *cur = n -> Parent;
        while(cur)
        {
            cur -> lockedDescendants ++;
            cur = cur -> Parent;
        }
        n -> isLocked = true;
        return true;
    }
    return false;
}
bool Unlock(Node *n)
{
    if(n && isLocked(n) && canUnlockorLock(n))
    {
        Node *cur = n -> Parent;
        while(cur)
        {
            cur -> lockedDescendants--;
            cur = cur -> Parent;
        }
        n -> isLocked = false;
        return true;
    }
    return false;
}
int main()
{
    ll n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        ll val;
        cin >> val;
        root = insert(val);
    }
    ll lockQueries,unlockQueries;
    cin >> lockQueries >> unlockQueries;
    while(lockQueries--)
    {
        ll lockVal;
        cin>> lockVal;
        Lock((Node*)mp[lockVal]);
    }
    inorder(root); cout<<"\n";
    while(unlockQueries--)
    {
        ll unlockVal;
        cin >> unlockVal;
        Unlock((Node*)mp[unlockVal]);
    }
    inorder(root);
    return 0;
}