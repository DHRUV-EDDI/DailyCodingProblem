#include<bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> v;
ll val;
ll findEleIndex(ll l, ll h)
{
    while(l <= h)
    {
        ll mid = l + (h-l)/2;
        if(v[mid] == val)
            return mid;
        if(v[l] <= v[mid])
        {
            if(v[l] <= val && val <= v[mid])
                h = mid - 1;
            else
                l = mid + 1;
        }
        else
        {
            if(v[mid] <= val && val <= v[h])
                l  = mid + 1;
            else
                h = mid - 1;
        }
    }
    return -1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        ll x; cin >> x;
        v.push_back(x);
    }
    cin >> val;
    ll idx = findEleIndex(0,n-1);
    cout<<idx<<"\n";
    return 0;
}