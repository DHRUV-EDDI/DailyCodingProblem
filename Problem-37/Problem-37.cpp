#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int m,n;
vector<vector<int>> v;
int countNeigh(int i, int j)
{
    int count =0;
    if( i+1 < m)
    {
        if(v[i+1][j] == 1) count++;
        count += ((j-1) >= 0 && v[i+1][j-1] == 1) ? 1 : 0;
        count += ((j+1) < n  && v[i+1][j+1] == 1) ? 1 : 0;
    }
    if( i-1 >= 0)
    {
        if(v[i-1][j] == 1) count++;
        count += ((j-1) >= 0 && v[i-1][j-1] == 1) ? 1 : 0;
        count += ((j+1) < n  && v[i-1][j+1] == 1) ? 1 : 0;
    }
    count += ((j-1) >= 0 && v[i][j-1] == 1) ? 1 : 0;
    count += ((j+1) < n  && v[i][j+1] == 1) ? 1 : 0;
    return count;
}
void conwayGame(vector<vector<int>>& board)
{
    v = board;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            int val = countNeigh(i,j);
            if(board[i][j] == 1)
            {
                if(val < 2 || val > 3) 
                    board[i][j] = 0;
            }
            else if(val == 3)
                board[i][j] = 1;
        }
    }
}
int main()
{
    vector<vector<int>> board;
    cin >> m >> n;
    board.resize(m,vector<int>(n));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            char ch; cin >> ch;
            board[i][j] = (ch == '*') ? 1 : 0;
        }
    }
    conwayGame(board);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(board[i][j]) cout<<"*";
            else cout<<".";
        }
        cout<<"\n";
    }
    return 0;
}