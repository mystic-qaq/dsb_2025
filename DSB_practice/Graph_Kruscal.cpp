#include <bits/stdc++.h>
using namespace std;
struct road{
    int s;
    int e;
    int cost;
};
struct cmp{
    bool operator()(road a,road b){
        return a.cost > b.cost;
    }
};
int pre[105];
int findroot(int a){
    while(pre[a] != 0){
        a = pre[a];
    }
    return a;
}
int main(){
    int n;
    cin>>n;
    int a,b,cost,flag;
    int cnt = 0;
    priority_queue<road,vector<road> ,cmp> pq;
    for(int i=1;i<=n*(n-1)/2;i++){
        cin>>a>>b>>cost>>flag;
        if(flag == 1){
            if(findroot(b) == findroot(a)){
                continue;
            }
            else{
                pre[findroot(b)] = findroot(a);
                cnt++;
            }
        }
        else{
            pq.push(road{a,b,cost});
        }
    }
    int sum = 0;
    while(cnt < n-1){
        road best = pq.top();
        pq.pop();
        if(findroot(best.s) == findroot(best.e)){
            continue;
        }
        else{
            sum += best.cost;
            pre[findroot(best.e)] = findroot(best.s);
            cnt++;
        }
    }
    cout<<sum<<endl;
    return 0;
}