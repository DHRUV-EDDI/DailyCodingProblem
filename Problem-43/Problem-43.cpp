#include<bits/stdc++.h>
using namespace std;
using ll = long long;
bool dp[1000][1000];
string s;
string findPalindrome()
{
    for(int i=s.length()-2;i>=0;i--)
    {
        for(int j=s.length()-1;j != i ; j--)
        {
            if(s[i] == s[j])
            {
                if(abs(i-j) == 1)
                    dp[i][j] = true;
                else
                    dp[i][j] = dp[i+1][j-1];
            }
        }
    }
    pair<ll,ll> p;
    ll len = 0;
    for(int i=0;i<s.length();i++)
    {
        for(int j=0;j<s.length();j++)
        {
            if(dp[i][j] == true)
            {
                if(j-i+1 > len)
                {
                    len = j-i+1;
                    p = {i,j};
                }
            }
        }
    }
    return s.substr(p.first,p.second-p.first+1);
}
int main()
{
    cin >> s;
    memset(dp,false,sizeof(dp));
    for(int i=0;i<s.length();i++)
        dp[i][i] = true;
    cout << findPalindrome();
    return 0;
}