#include<bits/stdc++.h>
using namespace std;
using ll = long long;
bool isDelimiter(char ch){

    switch(ch){
        case '/': return true;
        case ':': return true;
        case ' ': return true;
    }
    return false;
}
int main()
{
    string s;
    getline(cin,s);
    ll i,strt = 0,j=0;
    map<ll,ll> mp;
    vector<string> words;
    string delimiter;
    for(i=0;i<s.length();i++)
    {
        if(isDelimiter(s[i])){
            mp[i] = -1;
            if(strt < i){
                mp[strt] = i;
                words.push_back(s.substr(strt,i-strt));
            }
            delimiter += s[i];
            strt = i+1;
        }
    }
    if(strt < i){
        mp[strt] = i;
        words.push_back(s.substr(strt,i-strt));
    }
    string ans;
    ll k=words.size()-1;
    for(int i=0;i<s.length();)
    {
        if(mp[i] == -1){
            ans += delimiter[j++];
            i++;
        }
        else{
            ans +=  words[k--];
            i = mp[i];
        }
    }
    cout <<ans <<"\n";
    return 0;
}