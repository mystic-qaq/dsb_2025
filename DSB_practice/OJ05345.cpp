#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        char s;
        int k,sum=0;
        cin>>s>>k;
        if(s=='Q'){
            for(int j=1;j<=n;j++){
                if((a[j]>>k)&1){
                    sum++;
                }
            }
            cout<<sum<<endl;
        }
        else{
            for(int j=1;j<=n;j++){
                a[j]=(a[j]+k)%65536;
            }
        }
    }//65536=10000000000000000
    return 0;
}