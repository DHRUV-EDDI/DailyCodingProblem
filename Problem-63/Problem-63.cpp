#include<bits/stdc++.h>
using namespace std;
using ll = long long;
vector<vector<ll>> v;
ll m,n;
ll moveTopLeft(ll r, ll c)
{
    ll ans = -1 ;
    while( r >= 0 && c >= 0 && r < m && c < m && v[r][c] != 2)
    {
        if(v[r][c] == 1)
            ans++;
        else
            v[r][c] = 2;
        r--;
        c--;
    }
    return ans;
}
ll moveTopRight(ll r, ll c)
{
    ll ans = -1 ;
    while( r >= 0 && c >= 0 && r < m && c < m && v[r][c] != 2)
    {
        if(v[r][c] == 1)
            ans++;
        else
            v[r][c] = 2;
        r--;
        c++;
    }
    return ans;
}
ll moveDownLeft(ll r, ll c)
{
    ll ans = -1 ;
    while( r >= 0 && c >= 0 && r < m && c < m && v[r][c] != 2)
    {
        if(v[r][c] == 1)
            ans++;
        else
            v[r][c] = 2;
        r++;
        c--;
    }
    return ans;
}
ll moveDownRight(ll r, ll c)
{
    ll ans = -1 ;
    while( r >= 0 && c >= 0 && r < m && c < m && v[r][c] != 2)
    {
        if(v[r][c] == 1)
            ans++;
        else
            v[r][c] = 2;
        r++;
        c++;
    }
    return ans;
}
int main()
{
    cin >> n >> m;
    vector<pair<ll,ll>> p;
    v.resize(m,vector<ll>(m,0));
    for(int i=0;i<n;i++)
    {
        ll u,w;
        cin >> u >> w;
        v[u][w] = 1;
        p.push_back({u,w});
    }
    ll attacks = 0;
    for(auto i: p)
    {
        attacks += moveTopLeft(i.first, i.second) + moveTopRight(i.first, i.second)
                +  moveDownLeft(i.first,i.second) + moveDownRight(i.first,i.second);
    }
    cout<<attacks<<"\n";
    return 0;
}