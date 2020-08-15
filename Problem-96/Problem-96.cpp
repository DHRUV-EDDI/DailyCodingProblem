#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string s;
    cin >> s;
    ll sze;
    cin >> sze;
    set<char> st;
    for(int i=0;i<sze;i++)
    {
        char x; cin >> x;
        st.insert(x);
    }
    string ans;
    int set_count[30],strt=-1,count=0,end;
    memset(set_count,0,sizeof(set_count));
    for(int i=0;i<s.length();i++)
    {
        if(st.find(s[i]) != st.end())
        {
            if(strt == -1){
                count++;
                strt = i;
            }
            else{
                if(set_count[(int)(s[i]-'a')] == 0)
                    count++;
            }
            set_count[(int)(s[i]-'a')]++;
        }
        else continue;

        if(count == sze)
        {
            while(strt <= i){
                if(st.find(s[strt]) != st.end()){ 
                    if(set_count[(int)(s[strt]-'a')] > 1){
                        set_count[(int)(s[strt]-'a')]--;
                        strt++;
                    }else break;
                }
                else strt++;
            }
            if(ans.empty() || ans.length() > (i-strt+1)){
                ans = s.substr(strt, i-strt+1);
            }

        }
    }   
    cout <<ans << "\n";
    return 0;
}