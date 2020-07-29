#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    set<ll> s;
    vector<ll> v;
    ll n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        ll x; cin >> x;
        s.insert(x);
        v.push_back(x);
    }
    ll ans = 0;
    for(int i=0;i<n;i++)
    {
        if(s.insert(v[i]-1).second)
        {
            ll j = v[i],c=0;
            while(!s.insert(j).second)
            {   j++; c++; }
            ans = max(ans,c);
        }
    }
    cout << ans <<"\n";
    return 0;
}