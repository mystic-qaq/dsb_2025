#include<bits/stdc++.h>
using namespace std;
int a[55][55],b[55][55];
int ax{0},num{0},temp{0};
int m,n;
int dx[4]={0,-1,0,1};
int dy[4]={-1,0,1,0};
void dfs(int x,int y){
    if(x==0 or x==m+1 or y==0 or y==n+1){
        return;
    }
    for(int i=0;i<=3;i++){
        if(!((a[x][y]>>i)&1) and b[x+dx[i]][y+dy[i]]==0){
            b[x+dx[i]][y+dy[i]]=1;
            temp++;
            dfs(x+dx[i],y+dy[i]);
        }
    }
}
int main(){
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(b[i][j]==0){
                dfs(i,j);
                num++;
                ax=max(ax,temp);
                temp=0;
            }
        }
    }
    cout<<num<<endl<<ax<<endl;
    return 0;
}