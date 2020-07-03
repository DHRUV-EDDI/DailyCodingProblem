#include<bits/stdc++.h>
using namespace std;
using ll = long long;

// GRAPH + DP ===> 
// EXPLANATION https://blog.asarkar.org/assets/docs/algorithms-curated/Longest%20Path%20in%20a%20DAG%20-%20Khan.pdf
map<ll,vector<ll>> pre,adj;
string s;
ll dist[100][100];
vector<int> topologicalSort()
{
    vector<int> ans,indegree(s.length());
    queue<ll> q;
    for(int i=0;i<s.length();i++){
        indegree[i] = pre[i].size();
        if(indegree[i] == 0)
            q.push(i);
    }
    while(!q.empty())
    {
        ll cur = q.front();
        q.pop();
        ans.push_back(cur);
        for(auto i: adj[cur])
        {
            indegree[i]--;
            if(indegree[i] == 0)
                q.push(i);
        }
    }
    return ans;
}
ll findDistance(ll src, ll dest)
{
    if(dist[src][dest] != -1)
        return dist[src][dest];
    ll mx=-1;

    for(auto i: pre[dest])
        mx = max(mx,findDistance(src,i));
    return dist[src][dest] = mx+1;
}
int main()
{
    cin >> s;
    ll edges;
    cin >> edges;
    memset(dist,-1,sizeof(dist));
    while(edges--)
    {
        ll u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        pre[v].push_back(u);
    }
    vector<int> ans = topologicalSort();
    if(ans.size() != s.size())
    {
        cout<<"-1\n"; return 0;
    }
    vector<ll> strtPositions;
    for(int i=0;i<s.length();i++)
        if(pre[i].size() == 0)
            strtPositions.push_back(i);
    ll mxAns = INT_MIN;
    for(auto i: strtPositions)
    {
        for(auto j: ans)
            mxAns = max(mxAns,findDistance(i,j));
    }
    cout<<mxAns<<"\n";
    return 0;
}