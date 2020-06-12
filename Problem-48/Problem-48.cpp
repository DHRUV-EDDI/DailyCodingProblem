#include<bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> shuff;
void shuffle()
{   
    for(int i=0;i<shuff.size();i++)
    {
        int val = rand() % shuff.size();
        int temp = shuff[val];
        shuff[val] = shuff[i];
        shuff[i] = temp;
    }
}
int main()
{
    srand(time(0));
    ll k;
    cin >> k;
    for(int i=1;i<=k;i++) shuff.push_back(i);
    shuffle();
    for(auto i: shuff)
        cout<<i<<" ";
    return 0;
}