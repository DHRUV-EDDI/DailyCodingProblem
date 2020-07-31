#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    vector<pair<ll,ll>> points;
    ll n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        ll x,y;
        cin >> x >> y;
        points.push_back({x,y});
    }
    sort(points.begin(),points.end());
    ll ans = 0;
    for(int i=1;i<n;i++)
        ans += max(abs(points[i-1].first-points[i].first), abs(points[i-1].second-points[i].second));
    cout << ans<< "\n";
    return 0;
}