#include<bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> v;
vector<vector<ll>> ans;
void subsetSum(ll strt,vector<ll> cur,ll target)
{
    if(target < 0) return;
    if(target == 0)
    {
        ans.push_back(cur);
        return;
    }
    for(int i=strt;i<v.size();i++)
    {
        cur.push_back(v[i]);
        subsetSum(i+1,cur,target-v[i]);
        cur.pop_back();
    }
}
int main()
{
    ll n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        ll x; cin>>x;
        v.push_back(x);
    }
    ll target;
    vector<ll> k;
    cin >>target;
    // USING BITMASKING
    for(ll i=0;i<(1LL<<n);i++)
    {
        ll sum = 0;
        for(int j=0;j<n;j++)
        {
            if( i & (1 << j)){
                sum += v[j];
                k.push_back(v[j]);
            }
        }
        if(sum == target)
            ans.push_back(k);
        k.clear();
    }
    // USING BACKTRACKING
    //subsetSum(0,k,target);
    for(auto i: ans)
    {
        for(auto j: i)
            cout<<j<<" ";
        cout<<"\n";
    }
    return 0;
}