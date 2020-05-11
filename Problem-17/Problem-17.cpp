#include<bits/stdc++.h>
using namespace std;
using ll = long long;
 //TIME COMPLEXITY: O(N*k*K)
// SPACE COMPLEXITY: O(K)
int main()
{
    ll n,k;
    cin>>n>>k;
    vector<vector<ll>> v;
    v.resize(n,vector<ll>(k));
    for(int i=0;i<n;i++)
        for(int j=0;j<k;j++)
            cin>>v[i][j];
    ll dp[n+3][k+3];
    for(int i=0;i<n;i++)
        dp[0][i] = v[0][i];
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<k;j++)
        {
            dp[i][j] = INT_MAX;
            for(int mn =0;mn<k;mn++)
            {
                if(mn != j)
                    dp[i][j] = min (dp[i][j],dp[i-1][mn]);
            }
            dp[i][j] += v[i][j];
        }
    }
    ll ans = INT_MAX;
    ans = *min_element(dp[n-1],dp[n-1]+k);
    cout<<ans;
}