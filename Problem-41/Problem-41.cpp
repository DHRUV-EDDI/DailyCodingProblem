#include<bits/stdc++.h>
using namespace std;
using ll = long long;
class MaxStack
{
    stack<ll> st;
    ll maxEle = INT_MIN,mxSze=0,sze=0;
    public:
        MaxStack(ll size)
        {
            mxSze = size;
        }
        void push(ll ele)
        {
            if(sze > mxSze) return;
            if(ele >= maxEle)
            {
                st.push(maxEle);
                maxEle = ele;
            }
            st.push(ele);   sze++;
        }
        void pop()
        {
            if(sze == 0)    return;
            if(st.top() == maxEle)
            {
                st.pop();
                maxEle = st.top();
            }
            st.pop();   sze--;
        }
        ll getMax()
        {
            return maxEle;
        }
};
int main()
{
    ll n;
    cin >> n;
    MaxStack mx(n);
    ll queries;
    cin >> queries;
    while(queries--)
    {
        string s;
        cin >> s;
        if(s  == "push")
        {
            ll val;
            cin >> val;
            mx.push(val);
        }
        else if( s == "pop")
            mx.pop();
        else if( s == "max")
        {
            ll maxEl = mx.getMax();
            if(maxEl == INT_MIN)
                cout<<"Empty Stack\n";
            else
                cout<<maxEl<<"\n";
        }
    }
    return 0;
}