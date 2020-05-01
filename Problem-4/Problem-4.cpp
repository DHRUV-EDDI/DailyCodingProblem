#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n;
    cin>>n;
    map<ll,bool> mp;
    for(int i=0;i<n;i++)
    {
        ll x; cin >> x;
        mp[x] = true;
    }
    ll i=1;
    while(1)
    {
        if(mp.find(i) == mp.end())
        {
            cout<<i;
            return 0;
        }
        i++;
    }
    return 0;
}