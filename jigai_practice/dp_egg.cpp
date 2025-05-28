#include<bits/stdc++.h>
using namespace std;
int n,m,dp[105][15];
int main()
{
    while(cin>>n>>m)
    {
        memset(dp,0x3f,sizeof(dp));   //求最小值，初始化为无穷大 
        for(int i=1;i<=n;++i)dp[i][1] =i;
        for(int j=1;j<=m;++j)dp[0][j]=0;
        for(int i=1;i<=n;++i){
            for(int j=2;j<=m;++j){
                for(int k=1;k<=i;++k){
                    dp[i][j]=min(dp[i][j],max(dp[i-k][j],dp[k-1][j-1])+1);
                }       //分割枚举点，dp的常用做法
            }
        }
        cout<<dp[n][m]<<endl;
    }
    return 0;
}