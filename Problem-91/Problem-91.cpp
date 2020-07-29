#include<bits/stdc++.h>
using namespace std;
using ll = long long;
vector<vector<char>> v;
string s;
ll n,m;
bool exists(int i, int j, int si)
{
    if(i < 0 || j < 0 || i >= n || j >= m || s[si] != v[i][j])
        return false;
    if(si == s.length()-1) 
        return true;
    char ch = v[i][j];
    // cout << ch;
    v[i][j] = '.';
    bool ans = exists(i+1,j,si+1) || exists(i-1,j,si+1) 
        || exists(i,j+1,si+1) || exists(i,j-1,si+1);
    v[i][j] = ch;
    return ans;
}
int main()
{
    cin >> n >> m;
    v.resize(n,vector<char>(m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> v[i][j];
    cin >> s;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j] == s[0] && exists(i,j,0))
            {
                cout << "true\n";
                return 0;
            }
        }
    }
    cout <<"false\n";
    return 0;
}