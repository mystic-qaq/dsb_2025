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
}
int main(){
    int n,depth=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>tree[i][0]>>tree[i][1];
    }
    for(int i=1;i<=n;i++){
        depth=max(depth,dep(i));
    }
    cout<<depth<<endl;
    return 0;
}