#include<bits/stdc++.h>
using namespace std;
using ll = long long;
bool isFormed(char a,char b)
{
    if((a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b =='}'))
        return true;
    return false;
}
int main()
{
    string s;
    cin>>s;
    stack<char> st;
    for(int i=0;i<s.length();i++)
    {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            st.push(s[i]);
        else
        {
            if(!st.empty() && isFormed(st.top(),s[i]))
                st.pop();
            else
            {
                cout<<"false";
                return 0;
            }
        }
    }
    if(st.empty())
        cout<<"true";
    else
        cout<<"false";
    return 0;
}