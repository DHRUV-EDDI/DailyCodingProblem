#include<bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> relativeSorting(vector<ll> v, ll neg, ll pos, ll n)
{
    vector<ll> ans;
    ll i=neg,j=pos;
    while(i >= 0 && j < n){
        ll leftPart = v[i]*v[i];
        ll rightPart = v[j]*v[j];
        if(leftPart < rightPart){
            ans.push_back(leftPart);
            i--;
        }
        else{
            ans.push_back(rightPart);
            j++;
        }
    }
    while( i >= 0){
        ans.push_back(v[i]*v[i]);
        i--;
    }
    while( j < n){
        ans.push_back(v[j]*v[j]);
        j++;
    }
    return ans;
}
int  main(){
    ll n;
    cin >> n;
    vector<ll> v;
    for(int i=0;i<n;i++){
        ll x; cin >> x;
        v.push_back(x);
    }
    ll neg,pos=0;
    for(int i=0;i<n;i++)
    {
        if(v[i] >= 0)
            break;
        pos++;
    }
    neg = pos - 1;
    v = relativeSorting(v,neg,pos,n);
    for(auto i: v)
        cout << i << " ";
    return 0;
}