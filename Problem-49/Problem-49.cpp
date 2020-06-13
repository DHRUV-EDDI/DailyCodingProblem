#include<bits/stdc++.h>
using namespace std;
using ll = long long;
class LRU
{
    ll sze;
    map<ll,ll> hashTable;
    map<ll,list<ll>::iterator> keyAddress;
    list<ll> lst;
    public:
        LRU(ll cap)
        {
            sze = cap;
        }
        void setVal(ll key, ll val)
        {
            if(hashTable.find(key) != hashTable.end())
            {
                lst.erase(keyAddress[key]);
                lst.push_front(key);
                keyAddress[key] = lst.begin();
                hashTable[key] = val;
                return;
            }
            if(lst.size() == sze)
            {
                keyAddress.erase(lst.back());
                hashTable.erase(lst.back());
                lst.pop_back();
            }
            lst.push_front(key);
            keyAddress[key] = lst.begin();
            hashTable[key] = val;
        }
        ll getVal(ll key)
        {
            if(hashTable.find(key) != hashTable.end())
            {
                lst.erase(keyAddress[key]);
                lst.push_front(key);
                keyAddress[key] = lst.begin();
                return hashTable[key];
            }
            return -1;
        }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n; cin >> n;
    LRU test(n);
    ll queries;
    cin >> queries;
    for(int i=0;i<queries;i++)
    {
        string s; cin >> s;
        ll key,val;
        cin >> key;
        if(s == "SET")
        {
            cin >> val;
            test.setVal(key,val);
        }
        else
            cout<<test.getVal(key)<<"\n";
    }
    return 0;
}