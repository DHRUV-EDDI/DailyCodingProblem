#include<bits/stdc++.h>
using namespace std;
using ll = long long;
// Trie Datastructure makes this sum much easier.
typedef struct Node
{
    struct Node *children[26];
    bool isComplete;
}Node;
Node *root;
Node* getNode()
{
    Node *n = new Node;
    n -> isComplete = false;
    for(int i=0;i<26;i++)
        n -> children[i]= NULL;
    return n;
}
void insert(string s)
{
    Node *temp = root;
    for(int i=0;i<s.length();i++)
    {
        int in = s[i] - 'a';
        if(!temp -> children[in])
            temp -> children[in] = getNode();
        temp = temp -> children[in];
    }
    temp -> isComplete = true;
}
vector<string> search(string s)
{
    Node *temp = root;
    vector<string> ans;
    string word;
    for(int i=0;i<s.length();i++)
    {
        int in = s[i] - 'a';
        word += s[i];
        if(!temp->children[in])
        {
            ans.clear();
            return ans;
        }
        else if(temp -> children[in] -> isComplete)
        {
            temp = root;
            ans.push_back(word);
            word = "";
        }
        else
            temp = temp -> children[in];
    }
    return ans;
}
int main()
{
    root = getNode();
    ll n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string s; cin >> s;
        insert(s);
    }
    string original;
    cin>>original;
    vector<string> ans = search(original);
    if(ans.empty())
        cout<<"NULL";
    else
    { 
        for(auto i: ans)
            cout<<i<<" ";
    }
    return 0;
}