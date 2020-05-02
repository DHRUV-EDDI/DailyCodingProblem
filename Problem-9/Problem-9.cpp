#include<bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> v;
ll  dp[1002],n;
ll maxSum(ll i, ll prev) //Backtracking 
{
    if(i >= n) return 0;
    ll excluding = maxSum(i+1,prev),including = 0;
    if(prev + 1 != i)
        including = v[i] + maxSum(i+1,i);
    return max(including,excluding);
}
ll maxSumDP()
{
    dp[0] = v[0];
    if(n == 2)
        dp[1] = max(v[0],v[1]);
    
    for(int i=2;i<n;i++)
    {
        dp[i] = max(dp[i-1],dp[i-2]+v[i]);
        dp[i] = max(dp[i],v[i]);
    }
    return dp[n-1];
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++) 
        dp[i] = INT_MIN;
    for(int i=0;i<n;i++)
    {
        ll x; cin >> x;
        v.push_back(x);
    }
    cout<<maxSumDP();
    return 0;
}