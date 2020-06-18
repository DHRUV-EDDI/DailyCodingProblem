#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string s;
    getline(cin,s);
    stringstream ss(s);
    ll k, cur=0;
    cin >> k;
    string a,b;
    vector<string> v;
    ss >> a;
    b = a;
    while(ss >> a)
    {
        if(a.length()+b.length()+1 <= k)
        {
            b += ' ';
            b += a;
        }
        else
        {
            v.push_back(b);
            b = a;
        }
    }
    v.push_back(b);
    for(auto i: v)
        cout<<i<<"\n";
    return 0;
}