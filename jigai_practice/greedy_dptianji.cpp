#include<bits/stdc++.h>

using namespace std;
int a[1005],b[1005],dp[1005][1005];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    int n;
    while(scanf("%d",&n)){
        if(n==0){
            return 0;
        }
        else{
            for(int i=1;i<=n;++i){
                scanf("%d",&a[i]);
            }
            for(int i=1;i<=n;++i){
                scanf("%d",&b[i]);
            }
            sort(a+1,a+n+1,cmp);
            sort(b+1,b+n+1,cmp);
            for(int i=1;i<=n;++i){
                for(int j=1;j<=n;++j){
                    if(a[i]>b[j]){
                        dp[i][j]=max(dp[i-1][j-1]+200,max(dp[i-1][j],dp[i][j-1])-200);
                    }
                    else if(a[i]==b[j]){
                        dp[i][j]=max(dp[i-1][j-1],max(dp[i-1][j],dp[i][j-1])-200);
                    }
                    else{
                        dp[i][j]=max(dp[i-1][j],dp[i][j-1])-200;
                    }
                }
            }
            printf("%d\n",dp[n][n]);
        }
    }
    return 0;
}