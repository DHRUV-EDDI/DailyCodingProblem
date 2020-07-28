#include<bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> v;
void getAllPermnutations(int strt, int end)
{
    if(strt  == end)
    {
        for(auto i: v)
            cout << i<<" ";
        cout << "\n";
        return;
    }
    for(int i=strt;i<=end;i++)
    {
        swap(v[i],v[strt]);
        getAllPermnutations(strt+1,end);
        swap(v[i],v[strt]);
    }
}
int main()
{
    ll n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        ll x; cin >> x;
        v.push_back(x);
    }
    getAllPermnutations(0,n-1);
    return 0;
}