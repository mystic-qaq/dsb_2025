#include<bits/stdc++.h>
using namespace std;
string rev(string ss){
    string ans{};
    for(int i=0;i<=ss.length()-1;i++){
        ans=ss[i]+ans;
    }
    return ans;
}
bool isrev(string ss){
    if(ss==rev(ss)){
        return true;
    }
    return false;
}
int main(){
    string ss;
    while(cin>>ss){
        if(isrev(ss)){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}