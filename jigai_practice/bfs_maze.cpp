#include<bits/stdc++.h>
using namespace std;
int ans{0};
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
struct point{
    int x,y;
};
bool cmp(point a,point b){
    return a.x==b.x and a.y==b.y;
}
char a[105][105];
int vis[105][105];
queue<point> qu;
void bfs(point s,point t){
    bool flag=1;
    qu.push(s);
    vis[s.x][s.y]=0;
    while(true){
        for(int i=0;i<=3;i++){
            if(vis[qu.front().x+dx[i]][qu.front().y+dy[i]]==0){
                if(a[qu.front().x+dx[i]][qu.front().y+dy[i]]=='.'){
                    qu.push({qu.front().x+dx[i],qu.front().y+dy[i]});
                    vis[qu.front().x+dx[i]][qu.front().y+dy[i]]=vis[qu.front().x][qu.front().y]+1;    
                }
                if(cmp({qu.front().x+dx[i],qu.front().y+dy[i]},t)){
                    vis[t.x][t.y]=vis[qu.front().x][qu.front().y]+1;
                    flag=0;
                }
            }
        }
        if(flag==0){
            break;
        }
        qu.pop();
    }
    ans=vis[t.x][t.y];
}
int main(){
    int m,n;
    point s,t;
    cin>>m>>n;
    memset(a,'#',sizeof(a));
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            if(a[i][j]=='S'){
                s={i,j};
            }
            if(a[i][j]=='T'){
                t={i,j};
            }
        }
    }
    bfs(s,t);
    cout<<ans<<endl;
    return 0;
}