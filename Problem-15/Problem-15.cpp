#include<bits/stdc++.h>
using namespace std;
using ll = long long;
map<ll,string> m;
map<string,vector<string>> mp;
string ans;
void findLongestPath(string s,string v)
{
    if(mp[s].empty())
    {
        string j = ".ext";
        ll m = j.length()-1;
        for(int i=s.length()-1;i >= 0 && m >= 0;i--,m--)
        {
            if(s[i] != j[m])
                return;
        }
        if(ans.length() < v.length())
            ans = v;
        return;
    }
    for(auto i: mp[s])
        findLongestPath(i,v+"/"+i);
}
int main()
{
    //dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext
    string s,k;
    cin >> s;
    ll cur = 0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i] == '\\' && s[i+1] == 't')
        {
            ll c= 1;
            i+=2;
            while(s[i] == '\\' && s[i+1] == 't')
            {
                c++;
                i+=2;
            }
            k.pop_back();k.pop_back();
            if(m.find(cur-1) != m.end())
                mp[m[cur-1]].push_back(k);
            m[cur] = k;
            cur = c;
            k.clear();
        }
        k+= s[i];
    }
    mp[m[cur-1]].push_back(k);
    findLongestPath("dir","dir");
    cout<<ans.length();
    return 0;
}