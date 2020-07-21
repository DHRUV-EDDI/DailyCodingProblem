#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    srand(time(0));
    ll n,l;
    cin >> n >> l;
    bool visit[n+1];
    memset(visit,false,sizeof(visit));
    for(int i=0;i<l;i++)
    {
        ll x; cin >> x;
        visit[x] = true;
    }
    vector<ll> v;
    for(int i=0;i<n;i++)
        if(!visit[i]) v.push_back(i);
    ll val = rand() % (v.size());
    cout <<v[val] ;
    return 0;
}