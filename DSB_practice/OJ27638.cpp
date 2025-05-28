#include <bits/stdc++.h>
using namespace std;
int tree[105][2];
int dep(int x){
    if(x==-1){
        return 0;
    }
    else{
        return max(dep(tree[x][0]),dep(tree[x][1]))+1;
    }
}  //dfs
int main(){
    int n,cnt=0,depth=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>tree[i][0]>>tree[i][1];
        if(tree[i][0]==-1 and tree[i][1]==-1){
            cnt++;
        }
    }
    for(int i=0;i<n;i++){
        depth=max(depth,dep(i));
    }
    cout<<depth-1<<" "<<cnt<<endl;
    return 0;
}