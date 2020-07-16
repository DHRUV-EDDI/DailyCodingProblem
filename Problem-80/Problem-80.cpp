#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll pair=0,ans = 0;
    string s;
    cin >> s;
    for(int i=0;i<s.length();i++)
    {
        if(s[i] == '(') pair++;
        else if(pair == 0) ans++;
        else pair--;
    }
    cout<< ans + pair <<"\n";
    return 0;
}