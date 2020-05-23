#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define MAX 1000
string n,m;
ll dp[MAX][MAX];
  ////////////////
 //BOTTOM-UP DP//
////////////////
ll minimumCuts()
{
    for(int i=0;i<=m.length();i++) // If String n is empty
        dp[0][i] = i;
    for(int i=0;i<=n.length();i++) // IF String m is empty
        dp[i][0] = i;
    for(int i=1;i<=n.length();i++)
    {
        for(int j=1;j<=m.length();j++)
        {
            if(m[j-1] == n[i-1]) 
                dp[i][j] = dp[i-1][j-1];
            else 
                dp[i][j] = 1 + min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1])); // Minimum of insert, Delete , Update operations.
        }
    }
    return dp[n.length()][m.length()];
}
  ////////////////
 //TOP-DOWN  DP//
////////////////
int minCuts(int i,int j)
{
    if(i >= n.length())
        return m.length()-j;
    if(j >= m.length())
        return n.length()-i;
    if(dp[i][j] != -1)
        return dp[i][j];
    if(n[i] == m[j])
        return dp[i][j] = minCuts(i+1,j+1);
    else
        return dp[i][j] = 1 + min( minCuts(i,j+1), min( minCuts(i+1,j), minCuts(i+1,j+1) ) );
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m;
    memset(dp,0,sizeof(dp));
    cout<<minimumCuts();
    // memset(dp,-1,sizeof(dp));
    // cout<<minCuts(0,0);
    
}