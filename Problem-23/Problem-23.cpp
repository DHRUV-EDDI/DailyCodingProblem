#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MAX = 1e3+2;
string reg,val;
ll dp[MAX][MAX];
bool isPattern(int i,int j)
{
    if(i == reg.length() - 1 || j == val.length()-1)
    {
        if(i == reg.length() - 1 && j == val.length()-1) // Both are in last position
        {
            if(reg[i] == val[j] || reg[i] == '.' || reg[i] == '*')
                return true;
            return false;
        }
        else if(j != val.length() -1) // Expression is at last position
        {
            if(reg[i] == '*')
                return true;
            return false;
        }
        else    //text is at last position
        {
            if(reg[i] == val[j] || reg[i] == '.' || reg[i] == '*')
            {
                for(int k=i+1;k<reg.length();k++)
                    if(reg[k] != '*')
                        return false;
                return true;
            }
            return false;
        }
    }
    if(dp[i][j] != -1)
        return dp[i][j];
    if(reg[i] == val[j] || reg[i] == '.')
        return dp[i][j] = isPattern(i+1,j+1);
    else if(reg[i] == '*')
        return dp[i][j] = isPattern(i+1,j) || isPattern(i,j+1); //Either we consider it as empty [OR] sequence.
    else
        return dp[i][j] = false;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    cin>>reg>>val;
    if(isPattern(0,0))
        cout<<"true";
    else
        cout<<"false";
    return 0;
}