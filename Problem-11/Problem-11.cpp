#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n;
    cin>>n;
    map<string,set<string>> mp;
    vector<string> dict;
    for(int i=0;i<n;i++)
    {
        string s; cin>>s;
        for(int i=0;i<s.length();i++)
        {
            mp[s.substr(0,i+1)].insert(s);
        }
    }
    string s;
    cin>>s;
    for(auto i: mp[s])
        cout<<i<<" ";
    return 0;
}