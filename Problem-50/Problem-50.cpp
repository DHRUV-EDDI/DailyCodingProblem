#include<bits/stdc++.h>
using namespace std;
using ll = long long;
stack<ll> ori,temp;

void enQueue(ll val)
{
    while(!ori.empty())
    {
        temp.push(ori.top());
        ori.pop();
    }
    ori.push(val);
    while(!temp.empty())
    {
        ori.push(temp.top());
        temp.pop();
    }
}
ll deQueue()
{
    if(ori.empty())
        return -1;
    ll val = ori.top();
    ori.pop();
    return val;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        string s; cin >> s;
        if(s == "ENQUEUE")
        {
            ll val;
            cin >> val;
            enQueue(val);
        }
        else
            cout<<deQueue()<<"\n";
    }
    return 0;
}