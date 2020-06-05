#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n;
ll merge(vector<ll> &v,ll l,ll mid,ll h)
{
    ll temp[n],inver=0,i=l,j=mid,k=l;
    while(i <= (mid-1) && j <= h)
    {
        if(v[i] <= v[j])
            temp[k++] = v[i++];
        else
        {
            inver += (mid-i);
            // cout<<v[j]<<" "<<v[i]<<"\n";
            temp[k++] = v[j++];
        }
    }
    while(i <= (mid-1)) temp[k++] = v[i++];
    while(j <= h) temp[k++] = v[j++];
    for(int i=l;i<=h;i++)
        v[i] = temp[i];
    return inver;
}
ll mergeSort(vector<ll> &v,ll l, ll h)
{
    int inversions=0;
    if(l < h)
    {
        ll mid = l+(h-l)/2;
        inversions += mergeSort(v,l,mid);
        inversions += mergeSort(v,mid+1,h);
        inversions += merge(v,l,mid+1,h);
    }
    return inversions;
}
int main()
{
    cin >> n;
    vector<ll> v;
    for(int i=0;i<n;i++)
    {
        ll x; cin >> x;
        v.push_back(x);
    }
    cout<<mergeSort(v,0,n-1);
    return 0;
}