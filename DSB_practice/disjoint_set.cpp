#include<bits/stdc++.h>
using namespace std;
int root[50005];
int findroot(int x){
    if(root[x]==-1)return x;
    else{
        int t=findroot(root[x]);
        root[x]=t;
        return t;
    }
}

int main(){
    int n,m,num=1;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    while(cin>>n>>m){
        memset(root,-1,sizeof(root));
        if(m==0 and n==0){
            return 0;
        }
        else{
            for(int i=0;i<m;i++){
                int x,y;
                cin>>x>>y;
                int a=findroot(x);
                int b=findroot(y);
                if(a!=b){
                    root[a]=b;
                }
            }
            int cnt=0;
            for(int i=1;i<=n;i++){
                if(root[i]==-1){
                    cnt++;
                }
            }
            cout<<"Case "<<num<<": "<<cnt<<endl;
            num++;
        }
    }
    return 0;
}