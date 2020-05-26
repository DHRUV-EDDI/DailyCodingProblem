#include<bits/stdc++.h>
using namespace std;
using ll = long long;
bool dp[500][500];
int main()
{
    string s;
    cin >> s;
    pair<ll,ll> p;
    ll mx = INT_MIN;
    memset(dp,false,sizeof(dp));
    for(int i=0;i<s.length();i++)
        dp[i][i] = true;
    for(int i=s.length()-1;i>=0;i--)
    {
        for(int j=s.length()-1;j>i;j--)
        {
            if(s[i] == s[j])
            {
                if(abs(i-j) == 1)
                    dp[i][j] = dp[i][j-1];
                else
                    dp[i][j] = dp[i+1][j-1];
            }
            if(dp[i][j] && mx < (j-i+1))
            {
                p = {i,j};
                mx = j-i+1;
            }
        }
    }
    string ans;
    for(int i=s.length()-1;i>p.second;i--)
        ans += s[i];
    ans += s;
    for(int i=p.first-1;i>=0;i--)
        ans += s[i];
    cout<<ans;
    return 0;
}