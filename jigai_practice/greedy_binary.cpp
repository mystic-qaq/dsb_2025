#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,t,counta{0},countb{0},time{0};
    cin>>n;
    int a[n],b[n];
    for(int i=0;i<=n-1;i++){
        cin>>t;
        a[i]=t;
        if(a[i]==1){
            counta++;
        }
    }
    for(int i=0;i<=n-1;i++){
        cin>>t;
        b[i]=t;
        if(b[i]==1){
            countb++;
        }
    }
    if(counta!=countb){
        cout<<-1<<endl;
        return 0;
    }else{
        for(int i=0;i<=n-1;i++){
            if(a[i]!=b[i]){
                for(int j=1;j<=n-i-1;j++){
                    if(a[i+j]==b[i]){
                        a[i+j]=a[i];
                        a[i]=b[i];
                        time+=j;
                        break;
                    }
                }
            }
        }
    }
    cout<<time<<endl;//往往相邻对换可以考虑贪心算法！
    return 0;//贪心算法，难在验证算法的正确性！
}