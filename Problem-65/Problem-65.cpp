#include<bits/stdc++.h>
using namespace std;
using ll = long long;
// TIME COMPLEXITY: O(N)

ll getSum(ll n)
{
    ll sum = 0;
    while(n != 0)
    {
        sum += (n % 10);
        n /=10;
    }
    return sum;
}
int main()
{
    ll n,cur=19;
    cin >> n;
    for(;n;cur+=9)
    {
        if(getSum(cur) == 10)
            n--;
    }
    cout<<cur-9;
    return 0;
}