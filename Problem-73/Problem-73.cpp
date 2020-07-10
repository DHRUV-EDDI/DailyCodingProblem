#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll idx=-1,n;
    cin >> n;
    vector<ll> v;
    for(int i=0;i<n;i++)
    {
        ll x; cin >> x;
        v.push_back(x);
    }
    for(int i=0;i<n-1;i++)
    {
        if(v[i] > v[i+1])
        {
            if(idx == -1) idx = i;
            else{
                cout<<"false\n";
                return 0;
            }
        }
    }
    if(idx <= -1 || idx == (n-2) || v[idx-1] <= v[idx+1] || v[idx] <= v[idx+2])
        cout<<"true\n";
    else
        cout<<"false\n";
}