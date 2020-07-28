#include<bits/stdc++.h>
#define pii pair<ll,ll>
using namespace std;
using ll = long long;
map<ll,vector<pii>> mp;
ll get(ll key, ll time)
{
    if(mp[key].size() == 0) 
        return -1;
    ll prev = -1;
    for(int i=0; i < mp[key].size(); i++)
    {
        if(mp[key][i].first == time)
            return mp[key][i].second;
        if(mp[key][i].first > time)
            return prev;
        prev = mp[key][i].second;
    }
    return prev;
}
void Set(ll key, ll value, ll time)
{
    int i;
    for(i = 0; i< mp[key].size();i++)
        if(mp[key][i].first == time)
            break;
    
    if(i < mp[key].size())
        mp[key][i] = {time,value};
    else{
        mp[key].push_back({time,value});
        sort(mp[key].begin(),mp[key].end());
    }
}

int main()
{
    Set(1,1,0);
    Set(1,2,2);
    assert(get(1,1) == 1);
    assert(get(1,3) == 2);
    mp.clear();
    
    Set(1,1,5);
    assert(get(1,0) == -1);
    assert(get(1,10) == 1);
    mp.clear();

    Set(1,1,0);
    Set(1,2,0);
    assert(get(1,0) == 2);

    return 0;
}