#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n,k;
    cin>>n>>k;
    vector<vector<ll>> v;
    v.resize(n,vector<ll>(k));
    for(int i=0;i<n;i++)
        for(int j=0;j<k;j++)
            cin>>v[i][j];
    ll global_min=0,global_secmin=0,prev_mnidx=-1;
    for(int i=0;i<k;i++)
    {
        ll res = 0,temp_mn=INT_MAX,temp_secmn=INT_MAX,cur_idx=-1;
        for(int j=0;j<k;j++)
        {
            res = v[i][j];
            res += (j == prev_mnidx) ? global_secmin : global_min;
            
            if(res < temp_mn)
            {
                temp_secmn = temp_mn;
                temp_mn = res;
                cur_idx = j;
            }
            else if(res < temp_secmn)
                temp_secmn = res;
        }
        global_min = temp_mn;
        global_secmin = temp_secmn;
        prev_mnidx = cur_idx;
    }
    cout<<global_min;
    return 0;
}