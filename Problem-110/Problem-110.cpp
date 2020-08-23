#include<bits/stdc++.h>
using namespace std;
using ll = long long;
bool cmp(pair<ll,ll> a, pair<ll,ll> b){
    return a.second < b.second;
}
int main(){
    ll n;
    cin >> n;
    vector<pair<ll,ll>> v;
    for(int i=0;i<n;i++)
    {
        ll x,y; cin >> x >> y;
        v.push_back({x,y});
    }
    sort(v.begin(),v.end(),cmp);
    vector<ll> ans;
    ans.push_back(v[0].second);
    for(int i=1;i<n;i++){
        if(ans.back() < v[i].first || ans.back() > v[i].second)
            ans.push_back(v[i].second);
    }
    for(auto i: ans)
        cout << i <<" ";
    return 0;
}