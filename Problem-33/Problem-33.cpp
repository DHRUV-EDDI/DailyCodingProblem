#include<bits/stdc++.h>
using namespace std;
using ll = long long;
string s;
void pullFront(ll i, ll j,char ch)
{
    while(i<j)
    {
        if(s[i] == ch)
            i++;
        if(s[j] != ch)
            j--;
        if(s[i] != ch && s[j] == ch){
            swap(s[i],s[j]);
            i++; j--;
        }
    }
}
int main()
{
    cin >> s;
    ll rCount=0;
    pullFront(0,s.length()-1,'R');
    for(int i=0;i<s.length();i++)
        if(s[i] == 'R')
            rCount++;
    pullFront(rCount,s.length()-1,'G');
    cout<<s;
    return 0;
}