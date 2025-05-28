#include<bits/stdc++.h>
using namespace std;
#define inf 0x3fffffff;
int a[105],sum[105][105],dp[105][105];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            sum[i][j]=sum[i][j-1]+a[j];
        }
    }
    for(int i=1;i<=n;i++){
        dp[i][i]=0;
    }
    for(int v=1;v<n;v++){   // 注意内外循环顺序，应当看什么量恒变大
        for(int i=1;i<=n-v;i++){
            int j=i+v;
            dp[i][j]=inf;
            for(int k=i;k<j;k++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+sum[i][j]);
            }           // 区间压缩dp，有点技巧
        }
    }
    cout<<dp[1][n]<<endl;
    return 0;
}