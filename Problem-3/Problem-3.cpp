#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
typedef struct Tree
{
    struct Tree *left,*right;
    char data;
}Node;

Node* insert(Node *root,char val)
{
    if(root == NULL)
    {
        Node *n = new Node;
        n -> data = val;
        n -> left = n -> right = NULL;
        root = n;
        return root;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if(temp -> left == NULL)
        {
            Node *n = new Node;
            n -> data = val;
            n -> left = n -> right = NULL;
            temp -> left = n;
            break;
        }
        else
            q.push(temp -> left);
        
        if(temp -> right == NULL)
        {
            Node *n = new Node;
            n -> data = val;
            n -> left = n -> right = NULL;
            temp -> right = n;
            break;
        }
        else
            q.push(temp -> right);
    }
    return root;
}
void inorder(Node *root)
{
    if(root != NULL)
    {
        inorder(root -> left);
        cout<<root -> data<<" ";
        inorder(root -> right);
    }
}
void getPreorder(Node *root,string &s)
{
    if(root == NULL)
        s += "."; // Denotes a Node is null.
    else
    {
        s += root -> data;
        getPreorder(root -> left,s);
        getPreorder(root -> right,s);
    }
}
string serialize(Node *root)
{
    string s;
    getPreorder(root,s);
    free(root);
    return s;
}
Node* deserialize(string file,int &index)
{
    if(index >= file.length() || file[index] == '.')
    {
        index++;
        return NULL;
    }
    Node *n = new Node;
    n -> data = file[index++];
    n -> left = deserialize(file,index);
    n -> right = deserialize(file,index);
    return n;
}
int main()
{
    Node *root =NULL;
    ll n;
    cin>>n;
    while(n--)
    {
        char x; cin >> x;
        root = insert(root,x);
    }
    int index = 0;
    string file = serialize(root);
    cout<<"Serialization   : "<<file<<"\n";
    root = deserialize(file,index);
    cout<<"Deserialization : ";
    inorder(root);
    return 0;
}