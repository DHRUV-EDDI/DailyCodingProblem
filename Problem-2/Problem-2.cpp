#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> productArray(vector<ll> v,ll n)
{
    vector<ll> left(n),right(n);
    left[0] = right[n-1] = 1;
    for(int i=1;i<n;i++)
        left[i] = left[i-1]*v[i-1];
    for(int i=n-2;i>=0;i--)
        right[i] = right[i+1]*v[i+1];
    for(int i=0;i<n;i++)
        left[i] *= right[i];
    return left;
}
int main()
{
    ll n;
    cin>>n;
    vector<ll> v;
    for(int i=0;i<n;i++)
    {
        ll x; cin >> x;
        v.push_back(x);
    }
    vector<ll> ans = productArray(v,n);
    for(auto i: ans)
        cout<<i<<" ";
    return 0;
}