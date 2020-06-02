#include<bits/stdc++.h>
using namespace std;
using ll = long long;
map<string,vector<string>> mp;
vector<string> ans;
ll n;
bool stop = false;
void Itinerary(vector<string> &ans,string strt)
{
    vector<string> fwd;
    while(mp[strt].size() > 0)
    {
        string a = mp[strt][0];
        mp[strt].erase(mp[strt].begin()); 
        Itinerary(fwd,a);
        for(auto i: fwd)
            ans.push_back(i);
        fwd.clear();
    }
    ans.push_back(strt);
}
int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
    {
        string u,v;
        cin >>u >> v;
        mp[u].push_back(v);
    }
    for(auto &i: mp)
        sort(i.second.begin(),i.second.end());
    string strt;
    cin >> strt;
    Itinerary(ans,strt);
    reverse(ans.begin(),ans.end());
    for(auto i: ans)
        cout<<i<<" ";
    return 0;
}