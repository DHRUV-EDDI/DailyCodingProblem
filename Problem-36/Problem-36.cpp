#include<bits/stdc++.h>
using namespace std;
using ll = long long;
vector<string> v;
ll n,ans=0;
bool isSafe(ll i, ll k)
{
    for(int c=0;c<=i;c++)
        if(v[c][k] == 'Q')
            return false;
    // Left Diagonal
    ll r = i, c=k;
    while(r >= 0 && c >= 0)
    {
        if(v[r][c] == 'Q')  return false;
        r--; c--;
    }
    // Right Diagonal
    r = i; c= k;
    while(r >= 0 && c < n)
    {
        if(v[r][c] == 'Q') return false;
        r--; c++;
    }
    return true;
}
void NQueens(ll i)
{
    if(i == n)
    {
        ans++;
        return;
    }
    for(int k=0;k<n;k++)
    {
        if(isSafe(i,k))
        {
            v[i][k] = 'Q';
            NQueens(i+1);
            v[i][k] = '.';
        }
    }
}
int main()
{
    cin >> n;
    string s;
    for(int i=0;i<n;i++)
        s+='.';
    for(int i=0;i<n;i++)
        v.push_back(s);
    NQueens(0);
    cout<<ans<<"\n";
    return 0;
}