#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];
    ll k;
    cin >> k;
    bool ans= false;
    map<ll,ll> mp;
    for(int i=0;i<n;i++)
    {
        if( k < a[i]) continue;
        if(k == a[i] || mp.find(k - a[i]) != mp.end())
        {
            ans = true;
            break;
        }
        mp[a[i]]++;
    }
    (ans) ? cout<<"true" : cout<<"false";
    return 0;
}
