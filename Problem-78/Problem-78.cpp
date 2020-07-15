#include<bits/stdc++.h>
using namespace std;
using ll = long long;
vector<vector<ll>> v;
ll ans =0,n,m;
int xdir[] = {1,-1,0,0,1,1,-1,-1};
int ydir[] = {0,0,1,-1,1,-1,-1,1};
void countIslands(int i, int j)
{
    if(i < 0 || i >= m || j < 0 || j >= n || !v[i][j]) return;
    v[i][j] = 0;

    for(int dir = 0; dir < 8;dir++)
        countIslands(i+xdir[dir],j+ydir[dir]);
}
int main()
{
    cin >> m >> n;
    v.resize(m,vector<ll>(n,0));
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin >> v[i][j];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(v[i][j])
            {    
                ans++;    
                countIslands(i,j);
            }
    cout << ans <<"\n";
    return 0;
}