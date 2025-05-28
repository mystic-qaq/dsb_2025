#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,x,time;
    cin>>n>>x;
    for(int i=1;i<=n;i++){
        int num=i;
        while(num!=0){
            if(num%10==x){
                time++;
            }
            num=num/10;
        }   //一位一位地取出，是一种计数的好办法！
    }
    cout<<time<<endl;
    return 0;
}