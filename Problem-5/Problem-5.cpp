#include<bits/stdc++.h>
using namespace std;
template<typename T>
class createPair
{
    public:
    pair<T,T> p;
    createPair()
    {
        this -> p = {NULL,NULL};
    }
    pair<T,T> construct(T a, T b)
    {
        p = {a,b};
        return this -> p;
    }
    T First(const pair<T,T> s)
    {
        return s.first;
    }
    T Last( const pair<T,T> s)
    {
        return s.second;
    }
};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    createPair<int> p_int;
    createPair<char> p_char;
    cout<<"Integer pair:";
    cout<<p_int.First(p_int.construct(1,2))<<" ";
    cout<<p_int.Last(p_int.construct(3,9))<<"\n";
    cout<<"Character pair:";
    cout<<p_char.First(p_int.construct('a','e'))<<" ";
    cout<<p_char.Last(p_int.construct('f','z'));
    return 0;
}