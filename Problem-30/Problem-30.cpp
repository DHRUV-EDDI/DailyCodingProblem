#include<bits/stdc++.h>
using namespace std;
using ll= long long;
// Approach: https://www.dailycodingproblem.com/blog/how-to-find-arbitrage-opportunities-in-python/
vector<vector<double>> v;
bool bellmanFordAlgo(int src)
{
    //distace vector;
    double dist[v.size()+1];
    for(int i = 0;i<v.size();i++)
        dist[i] = INT_MAX;
    dist[src] = 0;
    for(int edge=0;edge<v.size();edge++)
        for(int node=0;node <v.size();node++)
            for(int neigh=0;neigh < v[node].size();neigh++)
                if(dist[node] != INT_MAX && dist[neigh] > dist[node] + v[node][neigh])
                    dist[neigh] = dist[node] + v[node][neigh];
    //Negative cycle check
    for(int edge=0;edge<v.size();edge++)
        for(int node=0;node <v.size();node++)
            for(int neigh=0;neigh < v[node].size();neigh++)
                if(dist[node] != INT_MAX && dist[neigh] > dist[node] + v[node][neigh])
                    return true;
    return false;
    // TIME COMPLEXITY : O(N^3) 
}
int main()
{
    ll n;
    cin>>n;
    v.resize(n,vector<double>(n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            double rate;
            cin >> rate;
            v[i][j] = -log10(rate);
        }
    if(bellmanFordAlgo(0))
        cout<<"true";
    else
        cout<<"false";
    return 0;
}