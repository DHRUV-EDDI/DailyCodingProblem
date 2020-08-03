#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MAX = 10005;
bool prime[MAX];

void sieve()
{
    memset(prime,true,sizeof(prime));
    prime[0] = prime[1] = false;
    for(int i=2;i<MAX;i++){
        for(int j = i*i;j<=MAX;j+=i)
            prime[j] = false;
    }
}
int main()
{
    sieve();
    ll n;
    cin >> n;
    for(int i=2;i<n;i++)
    {
        if(prime[i] && prime[n-i]){
            cout << i << " + "<< n-i << " = "<< n;
            break;
        }
    }
    return 0;
}