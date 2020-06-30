#include<bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> nums;
int maximumProduct() 
{
        
    int fmin=INT_MAX,smin=INT_MAX;
    int fmax=INT_MIN,smax=INT_MIN,tmax=INT_MIN;
    for(auto i: nums)
    {
        if(fmin >= i)
        {
            smin = fmin;
            fmin = i;
        }
        else if( smin >= i)
            smin = i;
    }
    for(auto i: nums)
    {
        if(fmax <= i)
        {
            tmax = smax;
            smax = fmax;
            fmax = i;
        }
        else if(smax <= i)
        {
            tmax = smax;
            smax = i;
        }
        else if(tmax <= i)
            tmax = i;
    }
    if(nums.size() == 3)
        return fmax*smax*tmax;
    else if(nums.size() == 4)
        return max(fmin*smin*tmax,fmax*smax*tmax);
    else
        return max(fmin*smin*fmax,fmax*smax*tmax);
}
int main()
{
    ll n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        ll x; cin >> x;
        nums.push_back(x);
    }
    cout << maximumProduct() <<"\n";
    return 0;
}