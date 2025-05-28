#include<bits/stdc++.h>
using namespace std;
int k,mark;
string ss,temp;
char ans[100],ansmin[100];
void dfs(int w,int rest){
    if(rest==0){
        //cout<<ans<<endl;
        if(strcmp(ans,ansmin)<0){
            strcpy(ansmin,ans);
        }
        return;
    }
    if(w>=ss.length()){
        return;
    }
    dfs(w+1,rest);
    ans[mark++]=ss[w];
    dfs(w+1,rest-1);
    mark--;
    ans[mark]=0;
}   //字符数组更适合于dfs
int main(){
    int n;
    cin>>n;
    memset(ansmin,'9',sizeof(ansmin));
    for(int i=1;i<=n;i++){
        cin>>ss>>k;
        dfs(0,ss.length()-k);
        cout<<ansmin<<endl;
        memset(ansmin,'9',sizeof(ansmin));
    }
    return 0;
}