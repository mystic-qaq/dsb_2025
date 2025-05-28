#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    map<string, string> mp;
    string ss;
    while(getline(cin,ss)){
        if(ss == ""){
            break;
        }
        else{
            int split=ss.find(' ');
            string s1=ss.substr(0,split);
            string s2=ss.substr(split+1,ss.length()-split-1);
            mp[s2] = s1;
        }
    }
    while(getline(cin,ss)){
        auto v=mp.find(ss);
        if(v!=mp.end()){
            cout<<v->second<<endl;
        }
        else{
            cout<<"eh"<<endl;
        }
    }
    return 0;
}