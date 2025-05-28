#include<bits/stdc++.h>
using namespace std;
int vis[205][205],a[205][205];
int m,n,xheart,yheart,x,y,p;
const int dr[4]={1,0,-1,0},dc[4]={0,1,0,-1};
void dfs(int r,int c){
    vis[r][c]=1;
    for(int i=0;i<=3;i++){
        int r1=r+dr[i],c1=c+dc[i];
        if(r1>=1 and r1<=m and c1>=1 and c1<=n and vis[r1][c1]==0 and a[r1][c1]<a[r][c]){
            a[r1][c1]=a[r][c];
            dfs(r1,c1);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    int k;
    cin>>k;
    for(int i=1;i<=k;i++){
        memset(vis,0,sizeof(vis));
        memset(a,0,sizeof(a));
        cin>>m>>n;
        for(int j=1;j<=m;j++){
            for(int l=1;l<=n;l++){
                cin>>a[j][l];
            }
        }
        cin>>xheart>>yheart;
        cin>>p;
        for(int j=1;j<=p;j++){
            cin>>x>>y;
            dfs(x,y);
        }
        if(vis[xheart][yheart]==1){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}