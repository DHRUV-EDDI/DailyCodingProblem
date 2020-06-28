#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll min_freq=0,sze=0,capacity;
unordered_map<ll,list<ll>> freq_list;
unordered_map<ll,list<ll>::iterator> key_itr;
unordered_map<ll,pair<ll,ll>> LFU;
ll get(ll key)
{
    /*
        STEPS:
            1) Base case return -1 if key not exists
            2) get value and frequency of a key
            3) get the frequency list of a key
            4) get the iterator address for a key
            5) delete the key in the frequency list
            6) Increment frequency and push key to current frequency
            7) update iterator address for a key
            8) if min_freq list is empty update min_freq
    */
    if(LFU.find(key) == LFU.end())  return -1;
        
    int val = LFU[key].first;
    int freq = LFU[key].second;
    auto it = key_itr[key];
        
    freq_list[freq].erase(it);
    freq_list[freq+1].push_back(key);
    key_itr[key] = --freq_list[freq+1].end();
    LFU[key].second +=1;
        
    if(freq_list[min_freq].size() == 0)
        min_freq += 1;
    return val;
}
    
void put(ll key, ll value) 
{
    /*
        STEPS:
            1)if capacity == 0 return
            2) if size == capacity remove front key from min_freq list
                a) erase iterator address for the key
                b) erase value,frequency for that key
                c) pop out from min_freq list
            3) insert a new key
                a) create a field of key-{value,frequency(1)}
                b) push key to frequency list 
                c) push iterator address of the key
                d) update min_freq
            4) Update size if size < capacity
    */
    if(capacity <= 0) return;
    if(get(key) != -1)
    {
        LFU[key].first = value;
        return;
    }
    if(sze == capacity)
    {
        int min_freq_key = freq_list[min_freq].front();
        key_itr.erase(min_freq_key);
        LFU.erase(min_freq_key);
        freq_list[min_freq].pop_front();
    }
    LFU[key] = {value,1};
    freq_list[1].push_back(key);
    key_itr[key] = --freq_list[1].end();
    min_freq = 1;
    if(sze < capacity) sze++;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> capacity;
    ll queries;
    cin >> queries;
    while(queries--)
    {
        ll key,val;
        string s;
        cin >> s >> key;
        if(s == "GET")
            cout<<get(key)<<"\n";
        else
        {
            cin >> val;
            put(key,val);
        }
    }
    return 0;
}