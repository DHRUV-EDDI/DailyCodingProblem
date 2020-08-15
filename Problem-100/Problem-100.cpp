#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string a,b;
    cin >> a >> b;
    if(b.length() != a.length()){
        cout << "False\n";
        return 0;
    }
    a += a;
    for(int i=0;i<b.length();i++)
    {
        if(a[i] == b[0]){
            string c = a.substr(i,b.length());
            if( c == b){
                cout <<"True\n";
                return 0;
            }
        }
    }
    cout << "False\n";
    return 0;
}