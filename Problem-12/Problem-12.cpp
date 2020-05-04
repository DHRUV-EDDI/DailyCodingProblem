#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MAX = 1e5+2;
const ll MOD = 1e9+7;
ll dp[MAX];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dp,0,sizeof(dp));
    dp[0]=0;dp[1]=1;dp[2]=2;
    for(int i=3;i<MAX;i++){
        dp[i]= (dp[i-1] % MOD +dp[i-2] % MOD)%MOD;
    }
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        cout<<dp[n]<<"\n";
    }
    return 0;
}