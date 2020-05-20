#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void fetchString(vector<string> ans,int arr[100],int j,int sp)
{
    if(j == 1)
    {
        cout<<ans[0]<<' ';
        while(sp--)
            cout<<' ';
        cout<<"\n";
        return;
    }
    if(sp > 0)
    {
        int req = (sp/(j-1)) > 0? (sp/(j-1)) : 1;
        for(int l=0;l<j;l++)
        {
            arr[l] += req;
            sp -=req;
            if(sp == 0)
                break;
        }
    }
    for(int l=0;l<j;l++)
    {
        cout<<ans[l];
        while(arr[l]--)
            cout<<' ';
    }
    cout<<"\n";
}
int main()
{
    ll n;
    cin>>n;
    vector<string> v;
    for(int i=0;i<n;i++)
    {
        string s; cin >> s;
        v.push_back(s);
    }
    ll k,cur=v[0].length();
    int arr[100];
    memset(arr,0,sizeof(arr));
    vector<string> ans(n);
    cin>>k;
    ans[0] =v[0];
    ll j=1;
    for(int i=1;i<n;i++)
    {
        if(cur+v[i].length()+1 <= k)
        {
            cur += v[i].length()+1;
            ans[j] = v[i];
            arr[j-1] = 1;
            //cout<<cur<<":";
            j++;
        }
        else
        {
            fetchString(ans,arr,j,k-cur);
            cur = v[i].length();
            memset(arr,0,sizeof(arr));
            ans[0] = v[i];
            j=1;
        }
    }
    fetchString(ans,arr,j,k-cur);
    return 0;
}