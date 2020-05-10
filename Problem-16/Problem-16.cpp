#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool isOperator(string k)
{
    if(k == "*" || k == "+" || k == "-" || k == "/")
        return true;
    return false;
}
ll operation(ll val1, ll val2, string op)
{
    if(op == "+")
        return val1+val2;
    else if(op == "*")
        return val1*val2;
    else if(op == "-")
        return val2-val1;
    else
        return val2/val1;
}
int main()
{
    vector<string> v;
    string s;
    while(cin >> s)
    {
        v.push_back(s);
    }
    stack<ll> st;
    for(int i=0;i<v.size();i++)
    {
        if(!isOperator(v[i]))
        {
            stringstream ss(v[i]);
            ll val;
            ss >> val;
            st.push(val);   
        }
        else
        {
            ll val1 = st.top();st.pop();
            ll val2 = st.top();st.pop();
            st.push(operation(val1,val2,v[i]));
            //cout<<st.top()<<":";
        }
    }
    cout<<st.top();
    return 0;
}