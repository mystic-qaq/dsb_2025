#include <bits/stdc++.h>
using namespace std;
int cost[30][30];
int vis[30];
int dis[30];
int res = 0;
int n;
//prim 最小生成树算法
void prim(){
    memset(dis,0x3f,sizeof(dis));
    dis[1] = 0;
    while(true){
        int V = -1;
        for(int u=1;u<=n;u++){
            if(vis[u]==0 and (V == -1 or dis[u]<dis[V])){
                V = u;
            }
        } 
        if(V == -1){
            break;
        }
        else{
            vis[V] = 1;
            res = res + dis[V];
            for(int i =1;i<=n;i++){
                dis[i] = min(dis[i] , cost[V][i]);
            }
        }

    }
}
int main(){
    cin>>n;
    memset(cost, 0x3f, sizeof(cost));
    char c,d;
    int m,k;
    for(int i=1;i<=n-1;i++){
        cin>>c>>m;
        for(int j=1;j<=m;j++){
            cin>>d>>k;
            cost[c-'A'+1][d-'A'+1] = k;
            cost[d-'A'+1][c-'A'+1] = k;
        }
    }
    prim();
    cout<<res<<endl;
    return 0;
}