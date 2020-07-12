#include<bits/stdc++.h>
using namespace std;
using ll = long long;
map<char,string> mp;
string s;
void allPossible(ll idx,string ans)
{
    if(idx > s.length() || idx < 0) return;

    if(idx == s.length())
    {
        cout << ans <<" ";
        return;
    }
    for(auto i: mp[s[idx]]){
        ans += i;
        allPossible(idx+1,ans);
        ans.pop_back();
    }
}
int main()
{
    mp['2'] = "abc";  mp['3'] = "def";
    mp['4'] = "ghi";  mp['5'] = "jkl";
    mp['6'] = "mno";  mp['7'] = "pqrs";   
    mp['8'] = "tuv";  mp['9'] = "wxyz";
    cin >> s;
    allPossible(0,"");
    return 0;
}