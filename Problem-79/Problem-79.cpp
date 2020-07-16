#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll x,y,b;
    cin >> x >> y >> b;
    cout << (x*b)+(y*abs(1-b));
    return 0;
}