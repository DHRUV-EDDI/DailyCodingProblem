#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string s,ans; 
    cin >> s;
    int strt=0,cur=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[strt] == s[i])
            cur++;
        else
        {
            ans += to_string(cur);
            cur = 1;
            ans += s[strt];
            strt = i;
        }
    }
    ans += to_string(cur);
    ans += s[strt];
    cout<<ans;
    return 0;
}