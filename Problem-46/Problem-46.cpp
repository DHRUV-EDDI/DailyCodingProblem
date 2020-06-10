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
    ll curSum=0,maxSum=0;
    for(int i=0;i<n;i++)
    {
        curSum += v[i];
        maxSum = max(maxSum,curSum);
        if(curSum < 0) curSum=0;
    }
    cout << maxSum << "\n";
    return 0;
}