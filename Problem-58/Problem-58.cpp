#include<bits/stdc++.h>
using namespace std;
using ll = long long;
vector<vector<ll>> v;
int main()
{
    ll m,n;
    cin >> m >> n;
    v.resize(m,vector<ll>(n,0));
    ll dp[m+2][n+2];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=m;i++)
        dp[i][1] = 1;
    for(int i=1;i<=n;i++)
        dp[1][i] = 1;
    for(int i=2;i<=m;i++)
        for(int j=2;j<=n;j++)
            dp[i][j] = dp[i][j-1] + dp[i-1][j];
    cout<<dp[m][n]<<"\n";
    return 0;
}