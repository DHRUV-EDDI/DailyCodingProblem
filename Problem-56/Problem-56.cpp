#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n;
vector<ll> v;
bool dp[1000][1000];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dp,false,sizeof(dp));
    cin >> n;
    for(int i=0;i<n;i++)
    {
        ll x; cin >> x;
        v.push_back(x);
    }
    ll sum = accumulate(v.begin(),v.end(),0);
    if( sum & 1)
        cout<<"false\n";
    else
    {
        ll req = sum/2;
        for(int i=0;i<=n;i++)
            dp[0][i] = true;
        for(int i=1;i<=req;i++){
            for(int j=1;j<=n;j++)
            {
                if(dp[i][j-1])
                {
                    dp[i][j] = dp[i][j-1];
                    continue;
                }
                if(v[j-1] <= i)
                    dp[i][j] = dp[i-v[j-1]][j-1];    
            }
        }
        if(dp[req][n])
            cout<<"true";
        else
            cout<<"false";
    }
    return 0;
}