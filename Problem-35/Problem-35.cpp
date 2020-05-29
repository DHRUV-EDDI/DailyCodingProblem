#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n;
vector<ll> v;
void subsetsBFS()
{
    queue<vector<ll>> q;
    cout<<"\n";
    for(int i=0;i<n;i++)
        q.push({i});
    while(!q.empty())
    {
        vector<ll> idx = q.front();
        q.pop();
        for(auto i: idx)
            cout<<v[i]<<" ";
        cout<<"\n";
        for(int i = idx[idx.size()-1]+1;i <n ;i++)
        {
            idx.push_back(i);
            q.push(idx);
            idx.pop_back();
        }
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        ll x; cin >> x;
        v.push_back(x);
    }
    subsetsBFS();
    return 0;
}