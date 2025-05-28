#include <bits/stdc++.h>
using namespace std;
int a[2006];
int main(){
    int n,m;
    cin>>n>>m;
    memset(a, 0x3f, sizeof(a)); //注意memset的正确用法
    for(int i=1;i<=n;i++){
        int k,t;
        cin>>k;
        if(k >= 0){
            t = k % m;
        }
        else{
            t = (k + int((-k)/m+1)*m) % m;
        }
        while(a[t]!=0x3f3f3f3f and a[t]!=k){   //重复的元素直接输出地址
            t = (t+1)%m;
        }
        a[t] = k;
        if(i!=n){
            cout<<t<<" ";
        }
        else{
            cout<<t;
        }
    }
    return 0;
}