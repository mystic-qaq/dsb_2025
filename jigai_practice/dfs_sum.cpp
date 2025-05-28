#include<bits/stdc++.h>
using namespace std;
int num[10005],k,ans,p;
bool cmp(int a,int b){
    return a>b;
}
void dfs(int w,int k){
    if(k==0){
        ans++;
        return;
    }//注意顺序！脑中模拟一遍深搜的过程
    if(w==p+1){
        return;
    }
    if(k<0){
        return;
    }
    if(k>0){
        dfs(w+1,k-num[w]);
        dfs(w+1,k);//要让搜索继续进行下去才行！
    }//24 13 11 7 动态调错！
}
int main(){
    string a{};
    getline(cin,a);
    int m{0};
    for(int i=0;i<=a.length()-1;i++){
        if(a[i]<='9' and a[i]>='0'){
            m=10*m+a[i]-'0';
        }
        if(a[i]==' '){
            num[p]=m;
            m=0;
            p++;
        }
    }
    num[p]=m;
    sort(num+0,num+p+1,cmp);
    while(cin>>k){
        if(k==0){
            break;
        }
        else{
            dfs(0,k);
            cout<<ans<<endl;
            ans=0;
        }
    }
    return 0;
}