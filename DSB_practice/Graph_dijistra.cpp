#include<bits/stdc++.h>
using namespace std;
int k,n,r;
//迪杰斯特拉；
struct node{
    int id;
    int len;
    int cost;
};    
struct cmp{
    bool operator()(node a,node b){
        return a.len > b.len;
    }   
}; //OOP方法，表示小的在前
vector<vector<node> > g(105);
int vis[105];
int main(){
    cin>>k>>n>>r;
    for(int i=1;i<=r;i++){
        int a1,a2,len,cost;
        cin>>a1>>a2>>len>>cost;
        g[a1].push_back(node{a2,len,cost});
    }
    bool flag = false;
    priority_queue<node,vector<node>, cmp> pq;
    pq.push(node{1,0,0});
    while(!pq.empty()){
        node temp = pq.top();
        if(temp.id == n){
            flag = true;
            cout<<temp.len<<endl;
            break;
        }
        pq.pop();
        for(auto v:g[temp.id]){
            if(!vis[v.id] and v.cost + temp.cost <= k){
                vis[v.id] == 1;
                pq.push(node{v.id,v.len+temp.len,v.cost+temp.cost});
            }
        }
    }
    if(flag == false){
        cout<<-1<<endl;
    }
    return 0;
}