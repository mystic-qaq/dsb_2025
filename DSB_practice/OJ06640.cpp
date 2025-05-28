#include <bits/stdc++.h>
using namespace std;
string ss[1005][105];
int main(){
    int n,m;
    cin>>n;
    for(int i=1;i<=n;i++){
        int len;
        cin>>len;
        for(int j=1;j<=len;j++){
            cin>>ss[i][j];
        }
    }
    cin>>m;
    for(int i=1;i<=m;i++){
        bool flag=1;
        string s;
        cin>>s;
        for(int j=1;j<=n;j++){
            for(int l=1;l<=100;l++){
                if(ss[j][l]==s){
                    cout<<j<<" ";
                    flag=0;
                    break;
                }
                if(ss[j][l]==""){
                    break;
                }
            }
        }
        if(flag==1){
            cout<<"NOT FOUND";
        }
        cout<<endl;
    }
    return 0;
}