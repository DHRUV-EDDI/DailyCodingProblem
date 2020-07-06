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
    ll dp[n];
    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    for(int i=1;i<n;i++)
    {
        ll val = 0;
        for(int j=0;j<i;j++)
            if(v[i] > v[j])
                val = max(val,dp[j]);
        dp[i] = val + 1;
    }
    cout<<*max_element(dp,dp+n);
    return 0;
}