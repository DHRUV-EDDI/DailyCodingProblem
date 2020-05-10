#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n,k,strt=0;
    cin >> n >> k;
    vector<ll> v;
    for(int i=0;i<n;i++)
    {
        ll x; cin >> x;
        v.push_back(x);
    }
    deque<ll> dq;
    for(int i=0;i<k;i++)
    {
        while(!(dq.empty()) && v[i] >= v[dq.front()])
            dq.pop_back();
        dq.push_back(i);
    }
    for(int i=k;i<n;i++)
    {
        cout<<v[dq.front()]<<" ";
        while(!(dq.empty()) && dq.front() <= (i-k) )
            dq.pop_front();
        while( !(dq.empty()) && v[i] >= v[dq.front()])
            dq.pop_back();
        dq.push_back(i);
    }
    cout<<v[dq.front()]<<" ";
    return 0;
}