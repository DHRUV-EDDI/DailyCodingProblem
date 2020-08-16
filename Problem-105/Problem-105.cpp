#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string s;
    getline(cin,s);
    ll i,strt = 0;
    for(i=0;i<s.length();i++)
    {
        if(s[i] == ' '){
            reverse(s.begin()+strt,s.begin()+i);
            strt = i+1;
        }
    }
    reverse(s.begin()+strt,s.begin()+i);
    reverse(s.begin(),s.end());
    cout << s;
    return 0;
}