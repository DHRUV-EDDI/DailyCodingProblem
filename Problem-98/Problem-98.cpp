#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,dp[1000];
vector<ll> v;
bool isPossible(ll idx){
    if(idx == n-1) return true;
    if(idx >= n || v[idx] == 0) return false;   
    if(dp[idx] != -1)
        return dp[idx];
    for(int i=1;i<=v[idx];i++)
    {
        if(isPossible(idx+i))
            return dp[idx] = true;
    }
    return dp[idx] = false;
}
int main()
{
    cin >> n;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        ll x; cin >> x;
        v.push_back(x);
    }
    if(isPossible(0))
        cout << "True\n";
    else
        cout << "False\n";
    return 0;
}