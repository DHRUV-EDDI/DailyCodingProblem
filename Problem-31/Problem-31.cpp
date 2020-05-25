#include<bits/stdc++.h>
using namespace std;
using ll = long long;
priority_queue<ll> mn; // mx_heap
priority_queue<ll,vector<ll>,greater<ll>> mx; //min_heap
void addNumber(ll val)
{
    if(mn.size() == 0 || val < mn.top() )
        mn.push(val);
    else
        mx.push(val);
}
void reBalance()
{
    if(abs(mn.size() - mx.size()) >= 2)
    {
        if(mx.size() > mn.size())
        {
            mn.push(mx.top());
            mx.pop();
        }
        else
        {
            mx.push(mn.top());
            mn.pop();
        }
    }
}
double getMedian()
{
    if(mn.size() == mx.size())
        return (mn.top()+mx.top()+0.0)/2;
    else if(mx.size() > mn.size())
        return mx.top();
    else
        return mn.top();
}
int main()
{
    /*
        APPROACH:
            dividing the numbers into two buckets to find a median based on a fact that Left of a median numbers
            are lower numbers and Right of it are higher numbers.
    */
    ll n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        ll val; cin>>val;
        addNumber(val);
        reBalance();
        cout<<getMedian()<<"\n";   
    }
    return 0;
}
