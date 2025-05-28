#include<bits/stdc++.h>
using namespace std;
struct interval{
    int a,b;
};
bool cmp(interval a,interval b){
    return a.b<b.b;
}
interval m[100005];
int main(){
    int n,cnt{1};
    cin>>n;
    for(int i=0;i<=n-1;i++){
        cin>>m[i].a>>m[i].b;
    }
    sort(m+0,m+n,cmp);
    int top=m[0].b;
    for(int i=1;i<=n-1;i++){
        if(m[i].a>=top){
            cnt++;
            top=m[i].b;
        }
    }
    cout<<cnt<<endl;
    return 0;
}