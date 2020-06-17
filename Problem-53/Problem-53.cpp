#include<bits/stdc++.h>
using namespace std;
using ll = long long;
vector<vector<ll>> v;
ll m,n,e;
bool isColourable(int node,int color[])
{
    if(node == n)
    {
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                if(v[i][j] && color[i] == color[j])
                    return false;
        return true;
    }
    for(int i=1;i<=m;i++){
        color[node] = i;
        if(isColourable(node+1,color))
            return true;
        color[node] = 0;
    }
    return false;
}
int main()
{
    cin >> n >> e >> m;
    v.resize(n+1,vector<ll>(n+1,0));
    for(int i=0;i<e;i++)
    {
        ll u,V;
        cin >> u >> V;
        v[u][V] = 1;
        v[V][u] = 1;
    }
    int color[m+1];
    memset(color,0,sizeof(color));
    if(isColourable(0,color))
        cout<<"Coloring is possible";
    else
        cout<<"Not possible";
    return 0;
}