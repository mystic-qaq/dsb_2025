#include <bits/stdc++.h>
using namespace std;
struct road{    
    int start;
    int end;
    int cost;
};
struct cmp{
    bool operator()(road a,road b){
        return a.cost > b.cost;
    }
};
vector<int> g[105];    
bool matrix[105][105];
   
int cnt = 0;    
int n;
bool is_com(int a,int b){
    bool vis[105];
    vis[a] = 1;
    if(a == b)return true;
    for(auto v:g[a]){
        if(!vis[v]){        
            vis[v] = 1;
            if(is_com(v,b))return true;
        }
    }
    return false;
}
int main(){

    cin>>n;
    priority_queue<road,vector<road>,cmp> pq;
    for(int i=1;i<=n*(n-1)/2;i++){
        int a,b,cost,flag;
        cin>>a>>b>>cost>>flag;
        if(flag == 1){
            if(!is_com(a,b)){
                cnt++;
            }
            g[a].push_back(b);
            g[b].push_back(a);
        }
        else{
            pq.push(road{a,b,cost});
        }
    }
    int sumcost = 0;
    while(cnt < n-1){
        road best = pq.top();
        pq.pop();
        if(is_com(best.start,best.end))continue;
        else{
            sumcost += best.cost;
            g[best.start].push_back(best.end);
            g[best.end].push_back(best.start);
            //cout<<best.start<<" "<<best.end<<" "<<best.cost<<endl;
            cnt++; 
        }
    }
    cout<<sumcost<<endl;
    return 0;
}