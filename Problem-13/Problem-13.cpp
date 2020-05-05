#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s,sub,res;
    cin >> s;
    ll strt=0,k,cur=0,ans=0;
    cin >> k;
    map<char,ll> mp;
    for(int i=0;i<s.length();i++)
    {
        mp[s[i]]++;
        if(k > 0)
        {
            if(mp[s[i]] == 1)
                k--;
            cur++;
            sub += s[i];
        }
        else
        {
            if(mp[s[i]] > 1){
                cur++;
                sub += s[i];
            }
            else
            {
                while(k == 0)
                {
                    if(mp[s[strt]] == 1)
                        k++;
                    mp[s[strt]]--;
                    sub.erase(0,1);
                    cur--;
                    strt++;
                }
                sub += s[i];
                cur++;
                k--;
            }
        }
        if(ans < cur)
        {
            ans = cur;
            res = sub;
        }
    }
    cout<<ans<<":"<<res;
    return 0;
}