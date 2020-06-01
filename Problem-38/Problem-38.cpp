#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n;
    cin >> n;
    vector<ll> v;
    for(int i=0;i<n;i++)
    {
        ll x; cin >> x;
        v.push_back(x);
    }
    ll ans = 0;
    for(int i=0;i<64;i++)
    {
        ll c = 0;
        for(int j=0;j<n;j++)
        {
            if( v[j] & (1LL << i))
                c++;
        }
        c = c % 3;
        if(c)
            ans |= ( 1LL << i);
    }
    cout<<ans<<"\n";
    return 0;
}