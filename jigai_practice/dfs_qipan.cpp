#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
char a[10][10];
bool b[10][10];//全局变量的设置对深搜是有利的
bool check(int x,int y){
    for(int i=1;i<=n;i++){
        if(b[x][i]==1 or b[i][y]==1){
            return false;
        }
    }
    return true;
}  //判断这个位置是否能放置棋子，深搜的控制条件；
void dfs(int row,int sum){
    if(sum==k){
        ans++;
        return;
    }
    if(row>n){
        return;
    }//深搜的边界条件；
    else{
        for(int i=1;i<=n;i++){
            if(a[row][i]=='#' and check(row,i)){
                b[row][i]=1;
                dfs(row+1,sum+1);
                b[row][i]=0;
            }//深搜的过程，注意回溯的初始化！
        }
        dfs(row+1,sum);//如果这一行啥都没取，接着向下走！
    }
}     //有点类似于N皇后问题
int main(){
    while(1){
        cin>>n>>k;
        if(n==-1 and k==-1){
            break;
        }
        else{
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    cin>>a[i][j];
                }
            }
            dfs(1,0);//从第一行开始深搜！
            cout<<ans<<endl;
            ans=0;
            memset(b,0,sizeof(b));//memset函数，可初始化数组！
        }
    }
    return 0;
}