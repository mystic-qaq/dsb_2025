#include<bits/stdc++.h>
using namespace std;
int a[105];
void movearray(int *pa,int n,int m){
    for(int i=0;i<m;i++){
        int temp=pa[n-1];
        for(int i=n-1;i>0;i--){
            pa[i]=pa[i-1];
        }
        pa[0]=temp;
    }
}       //这里把*pa理解为一个数组就好了！
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int *pa=a;
    movearray(pa,n,m);
    for(int i=0;i<=n-2;i++){
        cout<<a[i]<<" ";
    }
    cout<<a[n-1]<<endl;
    return 0;
}