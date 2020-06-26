#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,m;
vector<vector<ll>> v;
int main()
{
    cin >> n >> m;
    v.resize(n,vector<ll>(m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> v[i][j];
    ll rowStrt=0,colStrt=0,rowEnd=n-1,colEnd=m-1;
    while( rowStrt <= rowEnd && colStrt <= colEnd)
    {
        //LEFT TO RIGHT
        for(int i=colStrt;i<=colEnd;i++)
            cout<<v[rowStrt][i]<<" ";
        rowStrt++;
        // TOP TO BOTTOM        
        for(int i=rowStrt;i<=rowEnd;i++)
            cout<<v[i][colEnd]<<" ";
        colEnd--;
        //RIGHT TO LEFT
        if(rowStrt <= rowEnd)
        {
            for(int i=colEnd;i>=colStrt;i--)
                cout<<v[rowEnd][i]<<" ";
            rowEnd--;
        }
        //BOTTOM TO TOP
        if(colStrt <= colEnd)
        {
            for(int i=rowEnd;i>=rowStrt;i--)
                cout<<v[i][colStrt]<<" ";
            colStrt++;
        }
    }
    return 0;
}