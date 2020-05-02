#include<bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> v;
ll n;
ll maxSumNoAdj()
{
    if(n == 1)
        return v[0];
    if(n == 2)
        return max(v[0],v[1]);
    ll frst = v[0],scnd = max(v[0],v[1]);
    for(int i=2;i<n;i++)
    {
        ll temp = max(frst+v[i],scnd);
        temp = max(temp,v[i]);
        frst = scnd;
        scnd = temp;
    }
    return scnd;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        ll x; cin >> x;
        v.push_back(x);
    }
    cout<<maxSumNoAdj();
    return 0;
}