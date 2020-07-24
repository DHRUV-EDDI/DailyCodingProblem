#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n;
    cin >> n;
    map<string, vector<string>> mp;
    queue<string> q;
    map<string,ll> indegree;
    for(int i=0;i<n;i++)
    {
        string s,k; cin >> s;
        ll m; cin >> m;
        indegree[s] = m;
        for(int i=0;i<m;i++)
        {
            cin >> k;
            mp[k].push_back(s);
        }
        if(m == 0)
            q.push(s);
    }
    ll visited = 0;
    vector<string> ans;
    while(!q.empty())
    {
        string s = q.front();
        q.pop();
        ans.push_back(s);
        for(auto i: mp[s])
        {
            indegree[i]--;
            if(indegree[i] == 0)
                q.push(i);
        }
        visited++;
    }
    if(visited != n)
        cout << "Impossible to finish all courses";
    else
    {
        for(auto i: ans)
            cout << i << " ";
    }   
    return 0;
}