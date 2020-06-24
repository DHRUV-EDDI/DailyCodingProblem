#include<bits/stdc++.h>
using namespace std;
using ll = long long;
vector<vector<char>> board;
string word;
ll n,m;
bool  isLeftToRight(int r,int c)
{
    for(int i=0;i<word.length() && c < m;i++,c++)
    {
        if(word[i] != board[r][c])
            return false;
    }
    return true; 
}
bool isUpToDown(int r,int c)
{
    for(int i=0;i<word.length() && r < n;i++,r++)
    {
        if(word[i] != board[r][c])
            return false;
    }
    return true;
}
int main()
{
    cin >> n >> m;
    board.resize(n,vector<char>(m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> board[i][j];
    cin >> word;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(word[0] == board[i][j])
            {
                if(isLeftToRight(i,j) || isUpToDown(i,j))
                {
                    cout<<"true\n";
                    return 0;
                }
            }
        }
    cout<<"false\n";
    return 0;
}