#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define MAX 500
int main()
{
    ll n;
    cin>>n;
    vector<ll> v;
    for(int i=0;i<n;i++)
    {
        ll x; cin >> x;
        v.push_back(x);
    }
    /*
        ///////////////////////////
        => WITH EXTRA SPACE <= O(N)
        //////////////////////////
        ll left[MAX],right[MAX];
        left[0]=v[0];
        right[n-1] = v[n-1];
        for(int i=1;i<n;i++)
            left[i] = max(left[i-1],v[i]);
        for(int i=n-2;i>=0;i--)
            right[i] = max(right[i+1],v[i]);
        ll ans = 0;
        for(int i=0;i<n;i++)
            ans += min(left[i],right[i]) - v[i];
        cout<<ans;
    */
    ll ans=0,curL=0,curR=n-1,curML=0,curMR=0;
    while(curL <= curR)
    {
        if(v[curL] <= v[curR])
        {
            if(v[curL] >= curML) 
                curML = v[curL]; //Updating leftMax
            else
                ans += (curML-v[curL]);
            curL++;
        }
        else
        {
            if(v[curR] >= curMR) 
                curMR = v[curR]; // Updating RightMax
            else
                ans += (curMR-v[curR]);
            curR--;
        }
    }
    cout<<ans;
}