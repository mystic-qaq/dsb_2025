#include<bits/stdc++.h>
using namespace std;
int main(){
    string ans{};
    int a;
    cin>>a;
    while(a>0){
        ans=char(a%8+'0')+ans;
        a=a/8;
    }
    cout<<ans<<endl;
    return 0;
}