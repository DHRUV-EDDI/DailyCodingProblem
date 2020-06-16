#include<bits/stdc++.h>
using namespace std;
using ll = long long;
map<string,string> shortToUrl,urlToShort;
string encrypt = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
string Hash()
{
    string s;
    do
    {
        s = "www.tinyurl.com/";
        for(int i=1;i<=6;i++){
            s+= encrypt[rand()% encrypt.length()];
        }
    }while(shortToUrl.find(s) != shortToUrl.end());
    return s;
}
string shorten(string url)
{
    if(urlToShort.find(url) != urlToShort.end())
        return urlToShort[url];
    string s = Hash();
    shortToUrl[s] = url;
    urlToShort[url] = s;
    return s;
}
string restore(string shorten)
{
    if(shortToUrl.find(shorten) != shortToUrl.end()){
        string original = shortToUrl[shorten];
        shortToUrl.erase(shorten);
        urlToShort.erase(original);
        return original;
    }
    return "";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    srand(0);
    ll t;
    string url;
    cin >> t;
    while(t--)
    {
        string cmd;
        cin >> cmd >> url;
        if(cmd == "SHORTEN")
            cout << shorten(url)<<"\n";
        else
            cout<< restore(url)<<"\n";
    }
    return 0;
}