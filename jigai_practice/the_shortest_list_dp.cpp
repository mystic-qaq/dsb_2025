#include<bits/stdc++.h>
using namespace std;
double a[105];
int dp[105];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<=n-1;i++){
        cin>>a[i];
        dp[i]=1;
    }
    for(int i=1;i<=n-1;i++){
        for(int j=0;j<=i-1;j++){
            if(a[j]>=a[i]){
                dp[i]=fmax(dp[j]+1,dp[i]);
            }
        }
    }
    int dpmax{0};
    for(int i=0;i<=n-1;i++){
        dpmax=fmax(dpmax,dp[i]);
    }
    cout<<dpmax<<endl;
    return 0;
}