#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n,k;
    cin >> n >> k;
    vector<ll> v;
    for(int i=0;i<n;i++){
        ll x; cin >> x;
        v.push_back(x);
    }

    ll sum = 0,strt=0,end=INT_MIN;
    unordered_map<ll,ll> mp;
    for(int i=0;i<n;i++)
    {
        sum += v[i];

        if(sum == k){
            end = i;
            break;
        }

        if(mp.find(sum-k) != mp.end())
        {
            strt = mp[sum-k]+1;
            end =  i;
            break;
        }

        mp[sum] = i;
    }
    if(end != INT_MIN){
        for(int i=strt;i<=end;i++)
            cout << v[i] << " ";
    }
    else
        cout << " Not Possible ";
    return 0;
}