#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n,m,cnt=0;
    cin >> n >> m;
    char arr[n+1][m+1];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> arr[i][j];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(arr[j][i] > arr[j+1][i])
            {
                cnt++;
                break;
            }
        }
    }
    cout<<cnt<<"\n";
    return 0;
}