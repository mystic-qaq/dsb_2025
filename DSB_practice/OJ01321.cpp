#include <bits/stdc++.h>
using namespace std;
int n,k,sum=0;
char a[10][10];
bool b[10][10];
bool check(int x,int y){
    for(int i=1;i<=n;i++){
        if(b[x][i]==1 or b[i][y]==1){
            return false;
        }
    }
    return true;
}
void dfs(int x){
    if(k==0){
        sum++;
        return;
    }
    if(x>=n){
        return;
    }
    for(int i=x+1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]=='#' and check(i,j)){
                b[i][j]=1;
                k--;
                dfs(i);
                k++;
                b[i][j]=0;
                dfs(i+1);
            }
        }
    }
}
int main(){
    while(cin>>n>>k){
        if(n==-1 and k==-1){
            return 0;
        }
        else{
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    cin>>a[i][j];
                }
            }
            dfs(0);
            cout<<sum<<endl;
            memset(b,0,sizeof(b));
            sum=0;
        }
    }
    return 0;
}