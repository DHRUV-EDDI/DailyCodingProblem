#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n,x;
    cin >> n >> x;
    ll ans = 0;
    for(int i=1;i<=n;i++)
        if(x % i == 0 && x/i <= n)
            ans++;
    cout << ans << "\n";
    return 0;
}