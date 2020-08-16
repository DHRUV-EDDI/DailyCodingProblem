#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string word,s;
    cin >> word >> s;
    map<char,ll> mp;
    for(auto i: word)
        mp[i]++;
    for(int i=0;i<word.length();i++){
        mp[s[i]]--;
        if(mp[s[i]] == 0)
            mp.erase(s[i]);
    }
    vector<ll> ans;
    if(mp.empty())
        ans.push_back(0);
    for(int i=word.length();i<s.length();i++)
    {
        int strt = i-word.length();
        int end = i;
        mp[s[strt]]++;
        mp[s[end]]--;
        if(mp[s[end]] == 0)     mp.erase(s[end]);
        if(mp[s[strt]] == 0)    mp.erase(s[strt]);
        if(mp.empty())
            ans.push_back(i-word.length()+1);
    }
    for(auto i: ans)
        cout << i <<" ";
    return 0;
}