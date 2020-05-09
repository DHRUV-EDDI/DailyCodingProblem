#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
vector<ll> v;
void record(ll val)
{
    v.push_back(val);
}
ll get_last(ll i)
{
    if(i >= v.size() || i < 0) return -1;
    return v[v.size()-i];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    while(cin >> s)
    {
        if(s == "record")
        {
            ll val;
            cin>>val;
            record(val);
        }
        else if(s == "get_last")
        {
            ll idx;
            cin>>idx;
            cout<<get_last(idx)<<"\n";
        }
    }
    //TODO
    return 0;
}