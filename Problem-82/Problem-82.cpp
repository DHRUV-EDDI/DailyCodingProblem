#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll a,b;
    cin >> a >> b;
    ll cnt = 0;
    ll x = a, y = b;
    a = abs(a);
    b = abs(b);
    while(a >= b)
    {
        a -= b;
        cnt++;
    }
    if((x < 0 && y < 0 )|| (x > 0 && y > 0))
        cout << cnt;
    else
        cout << -cnt;
    return 0;
}