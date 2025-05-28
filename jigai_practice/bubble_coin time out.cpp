#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    long long int sum{0};
    cin>>n>>k;
    int a[n-1]{};
    for(int i=0;i<=n-1;i++){
        cin>>a[i];
        sum+=a[i];
    }
    int b[k+1]{};     //开这样的数组，其实是被允许的！
    for(int j=0;j<=k;j++){
        for(int m=j;m<=j+n-k-1;m++){
           b[j]=b[j]+a[m];
        }
    }
    int min=b[0];
    for(int j=1;j<=k;j++){
        min=fmin(min,b[j]);    
    }                         //取最小的好办法，免去了冒泡排序的麻烦！
    cout<<sum-min<<endl;
    return 0;
}