#include<bits/stdc++.h>
using namespace std;
using ll = long long;
//TIME COMPLEXITY: O(8 ^ N ^ 2)
ll n, board[100][100],
      xdir[] = {2,1,-1,-2,-2,-1,1,2}, 
      ydir[] = {1,2,2,1,-1,-2,-2,-1};
ll findKnightTour(int i, int j, int val)
{
    if(i < 0 || j < 0 || i >= n || j >= n || board[i][j] > 0)
        return 0;
    board[i][j] = val;
    if(val == (n*n))
        return  1;
    for(int k=0;k<8;k++)
        if(findKnightTour(xdir[k]+i,ydir[k]+j,val+1))
            return 1;
    board[i][j] = 0;
    return 0;
}
int main()
{
    cin >> n;
    ll ans = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            memset(board,0,sizeof(board));
            ans += findKnightTour(i,j,1);
        }
    }
    cout<<ans<<"\n";
    return 0;
}