#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,t{0};
    cin>>n;
    int dist[n+1]{},num[n]{};
    for(int i=0;i<=n-1;i++){
        cin>>num[i]>>dist[i+1];
        dist[i+1]=dist[i+1]+dist[i];//降低了时间复杂度！
    }                                         
    long long int sum{0},summin{10000000000};
    for(int i=0;i<=n-1;i++){
        sum=0;//务必记得初始化变量！发现问题及时调试；
        for(int j=0;j<=n-i-1;j++){
            sum+=fmin(dist[i+j]-dist[i],dist[n]-dist[i+j]+dist[i])*num[i+j];
        }
        for(int j=0;j<=i;j++){
            sum+=fmin(dist[n]-dist[i]+dist[j],dist[i]-dist[j])*num[j];
        }
        summin=fmin(summin,sum);
        if(sum==summin){
            t=i;
        }
    }
    cout<<t<<","<<summin<<endl;
    return 0;
}