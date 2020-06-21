#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll power(ll x, ll y)
{
    ll res = 1;
    while(y > 0)
    {
        if(y & 1)
            res *= x;
        y = y >> 1;
        x = x * x;
    }
    return res;
}
int main()
{
    ll x,y;
    cin >> x >> y;
    cout << power(x,y);
    return 0;
}