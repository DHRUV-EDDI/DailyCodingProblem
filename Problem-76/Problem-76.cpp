#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll countCharacters()
{
    ifstream fin("sample.txt");
    ll cunt = 0;
    while(fin)
    {
        char ch;
        fin.get(ch);
        cunt ++;
    }
    return cunt;
}
int main () {
   fstream File("sample.txt", ios::in | ios::out );
   ll n,cur=0,cnt = countCharacters();
   cin >> n;
   while(1)
   {
       string s; cin >> s;
       if(s == "readN")
       {
           ll strt = cur;
           ll end = min(cur+n,cnt);
           cur += n;
           if(strt > end){ cout<<"\n"; continue;}
           File.seekg(strt, ios::beg);
           char F[end-strt+2];
           File.read(F, end-strt);
           F[end-strt] = 0;
           cout <<F<< "\n";
       }
       else {
           File.close();
           return 0;
       }
   }
   return 0;  
}