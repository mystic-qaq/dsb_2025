#include <bits/stdc++.h>
using namespace std;
struct worker{
    string name;
    int num;
};
worker w[10];
void f(){
    for(int i=0;i<=9;i++){
        cin>>w[i].name>>w[i].num;
    }
}
bool cmp(worker a,worker b){
    return a.num<b.num;
}
void find(){
    int a,left=0,right=9;
    cin>>a;
    while(left<right){
        if(a<w[left].num or a>w[right].num){
            cout<<"NOFOUND"<<endl;
            return;
        }
        else if(a==w[left].num){
            cout<<w[left].name<<endl;
            return;
        }
        else if(a==w[right].num){
            cout<<w[right].name<<endl;
            return;
        }
        else{
            if(a<=w[(right+left)/2].num){
                right=(right+left)/2;
            }
            else{
                left=(right+left)/2+1;//注意这个+1是小细节
            }
        }
    }
    if(a==w[left].num){
        cout<<w[left].name<<endl;
    }
    else{
        cout<<"NOFOUND"<<endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    f();
    sort(w,w+10,cmp);
    for(int i=0;i<=9;i++){
        cout<<w[i].name<<"-"<<w[i].num<<endl;
    }
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        find();
    }
    return 0;
}
