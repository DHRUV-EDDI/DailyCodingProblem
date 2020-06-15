#include<bits/stdc++.h>
using namespace std;
using ll = long long;
vector<vector<ll>> v;
bool findPosition(int &curRow,int &curCol)
{
    for(curRow=0;curRow<9;curRow++)
        for(curCol=0;curCol<9;curCol++)
            if(v[curRow][curCol] == 0)
                return true;
    return false;
}
bool isSafe(int r, int c, int val)
{
    // Used in row or col
    for(int i=0;i<9;i++)
        if(v[r][i] == val || v[i][c] == val) return false;
    
    //used in box
    r -= (r % 3);
    c -= (c % 3);
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(v[i+r][j+c] == val) return false;
    return true;
}
bool sudoku()
{
    int curRow=0 , curCol=0;
    if(!findPosition(curRow,curCol))
        return true;
    for(int i=1;i<=9;i++)
    {
        if(isSafe(curRow,curCol,i))
        {
            v[curRow][curCol] = i;
            if(sudoku()) return true;
            v[curRow][curCol] = 0;
        }
    }
    return false;
}

int main()
{
    v.resize(10,vector<ll>(10,0));
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            cin >> v[i][j];
    if(sudoku())
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
                cout<<v[i][j]<<" ";
            cout<<"\n";
        }
    }
    else
        cout<<"Not Possible";
    return 0;
}