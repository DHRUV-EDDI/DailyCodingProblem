#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(s) (s).begin(),(s).end()
vector<ll> x,y;
int main()
{
    ll n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        ll a,b;
        cin>>a>>b;
        x.push_back(a);
        y.push_back(b);
    }
    sort(ALL(x));
    sort(ALL(y));
    ll strt=0,end=0,cur_room=0,maxAns=INT_MIN;
    while(strt < x.size() || end < y.size())
    {
        if(strt >= x.size()) break;
        if(x[strt] < y[end])
        {
            cur_room++;
            strt++;
        }
        else
        {
            cur_room--;
            end++;
        }
        maxAns = max(cur_room,maxAns);
    }
    cout<<maxAns;
    return 0;
}