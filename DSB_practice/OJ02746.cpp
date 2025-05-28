#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    while(cin>>n>>m){
        if(n==0 and m==0){
            return 0;
        }
        else{
            int ans=0;
            for(int i=2;i<=n;i++){
                ans=(ans+m)%i;
            }
            cout<<ans+1<<endl;
        }
    }   //约瑟夫问题的递推公式
    return 0;
}