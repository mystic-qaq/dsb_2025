#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,a[201]{},x,t,sum{0};
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        a[i]=x;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i;j++){
            if(a[j+1]<a[j]){
                t=a[j],a[j]=a[j+1],a[j+1]=t;
            }
        }
    }    //冒泡排序的具体实现
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
              if(a[i]!=0 and __gcd(a[i],a[j])==1){
              sum++; 
              if(sum==1){
                printf("%d/%d",a[i],a[j]);
              }
              else{
                printf(",%d/%d",a[i],a[j]);
              } 
            }
        }
    }
    if(sum==0){
       printf("NO");
    }
    return 0;    
}
