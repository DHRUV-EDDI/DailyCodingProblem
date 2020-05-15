#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll r,c,si,sj,ei,ej;
vector<vector<ll>> v;
int xdir[]={-1,0,1,0};
int ydir[]={0,1,0,-1};
bool visit[1000][1000];
ll minSteps(ll i, ll j)
{
    if(i < 0 || j < 0 || i >= r || j >= c || visit[i][j] || !v[i][j])
        return INT_MAX;
    if(i == ei && j == ej)
        return 0;
    visit[i][j] = true;
    ll val = INT_MAX;
    for(int k=0;k<4;k++)
        val = min(val,minSteps(i+xdir[k],j+ydir[k]));
    return 1+val;
}
int main()
{
    memset(visit,false,sizeof(visit));
    cin>>r>>c;
    v.resize(r,vector<ll>(c,0));
    for(int i=0;i<r;i++)
    {
        for(int j=0; j< c;j++)
        {
            char ch; cin >> ch;
            if(ch == 'f')
                v[i][j] = 1;
        }
    }
    cin>>si>>sj>>ei>>ej;
    ll val = minSteps(si,sj);
    if(val >= INT_MAX)
        cout<<"0";
    else
        cout<<val;
    return 0;
}