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
    ll rightMax[n+2];
    rightMax[n-1] = INT_MIN;
    for(int i=n-2;i>=0;i--)
        rightMax[i] = max(rightMax[i+1],v[i+1]);
    ll mx = INT_MIN;
    for(int i=0;i<n;i++)
        mx = max(mx, rightMax[i]-v[i]);
    cout<<mx;
    return 0;
}