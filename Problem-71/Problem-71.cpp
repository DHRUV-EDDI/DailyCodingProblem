#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    vector<pair<ll,ll>> v,ans;
    ll n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        ll u,w;
        cin >> u >> w;
        v.push_back({u,w});
    }
    sort(v.begin(),v.end());
    ll strt=v[0].first,end=v[0].second;
    for(int i=1;i<n;i++)
    {
        if(v[i].first > end)
        {
            ans.push_back({strt,end});
            strt = v[i].first;
            end = v[i].second;
        }
        else
        {
            strt = min(strt,v[i].first);
            end = max(end,v[i].second);
        }
    }
    ans.push_back({strt,end});
    for(auto i: ans)
        cout<<"("<<i.first<<", "<<i.second<<")\n";
    return 0;
}