#include<bits/stdc++.h>
using namespace std;
int ans{0};
void dfs(int m,int k){//表示大于等于m的k的因数；
    if(k==1){
        ans++;
        return;
    }
    else{
        for(int i=m;i<=k;i++){
            if(k%i==0){
                dfs(i,k/i);
            }
        }
    }
}

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int t;
        cin>>t;
        dfs(2,t);
        cout<<ans<<endl;
        ans=0;
    }
    return 0;
}