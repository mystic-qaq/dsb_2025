#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a<b;
}
vector<int> G[10005];
int in[10005];
bool vis[10005];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        G[x].push_back(y);
        in[y]++;
    }
    for(int i=1;i<=n;i++){
        sort(G[i].begin(),G[i].end(),cmp);
    }
    int cnt = 0;
    while(cnt != n){
        for(int i=1;i<=n;i++){
            if(vis[i]){
                continue;
            }
            if(in[i] == 0){
                cout<<"v"<<i<<" ";
                cnt++;
                for(auto j: G[i]){
                    in[j]--;
                }
                vis[i] = true;
                break;
            }
        }
    }
    return 0;
}