#include<bits/stdc++.h>
using namespace std;
int main(){
    int flag{0};
    int a;
    cin>>a;
    getchar();//细节,去除原有的回车;
    for(int i=1;i<=a;i++){
        flag=0;
        string s{};
        getline(cin,s);
        if((s[0]>='a' and s[0]<='z') or (s[0]>='A' and s[0]<='Z') or s[0]=='_'){
            for(int j=1;j<=int(s.length())-1;j++){
                if((s[j]>='0' and s[j]<='9') or (s[j]>='a' and s[j]<='z') or (s[j]>='A' and s[j]<='Z') or s[j]=='_'){
                    continue;
                }
                else{
                    cout<<"0"<<endl;
                    flag=1;
                    break;
                }
            }
            if(flag==0)cout<<"1"<<endl;
        } else {
            cout<<"0"<<endl;
        }
    }
    return 0;
}