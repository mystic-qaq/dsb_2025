#include <bits/stdc++.h>
using namespace std;
string a{};
bool vis[6];
char path[7];       //  dfs中，应该说字符数组是记忆化的一个好办法
void dfs(int k){
    if(k>=a.length()){
        for(int i=0;i<=k-1;i++){
            cout<<path[i];
        }
        cout<<endl;
        return;
    }
    else{
        for(int i=0;i<=a.length()-1;i++){
            if(vis[i]==0){
                path[k]=a[i];
                vis[i]=1;
                dfs(k+1);
                vis[i]=0;
            }
        }
    }
}
int main(){
    cin>>a;
    dfs(0);
    return 0;
}
    