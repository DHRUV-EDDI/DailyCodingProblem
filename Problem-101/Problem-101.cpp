#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n;
    cin >> n;
    /*
        Algorithm:
            => The question is to to right shift the even bits and left shift the odd bits in x.
            => All even bits set binary number is 0xAAAAAAAA
            => All Odd bits set binary number  is 0x55555555
            => We can shift the even bits in the n by doing bitwise and to even-bit number and viceversa.
            => the resultant will be combine result of both.
    */
   cout << (((n & 0xAAAAAAAA) >> 1) | ((n & 0x55555555) << 1)) <<"\n";
    return 0;
}