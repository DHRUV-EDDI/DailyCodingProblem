#include<bits/stdc++.h>
using namespace std;
using ll = long long;
map<int,char> mp;
string s;
vector<string> ans;
void Decode(int idx,string res)
{
    if(s[idx] == '0') return;
    if(idx >= s.length())
    {
        ans.push_back(res);
        return;
    }
    int val = (int)(s[idx]-'0');
    res += mp[val];
    Decode(idx+1,res);
    res.pop_back();
    if(s[idx] < '3' && idx+1 < s.length())
    {
        val = val * 10 + (int)(s[idx+1]-'0');
        res+=mp[val];
        Decode(idx+2,res);
        res.pop_back();
    }
}
int main()
{
    for(int i=1;i<=26;i++)
        mp[i]=(char)('a'+(i-1));

    cin>>s;
    Decode(0,"");
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i];
        if(i != ans.size()-1)
            cout<<", ";
    }
    cout<<"\n"<<ans.size();
    return 0;
}