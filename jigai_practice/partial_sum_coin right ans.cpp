#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    int a[n]{};
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]+=a[i-1];    //tips:前缀和和差分，可以免去开列表的麻烦，使运行速度提升！
    }
    int max=0;
    for(int j=0;j<=k;j++){
        max=fmax(max,a[j]+a[n]-a[n-k+j]);    //注意细节！
    }
    cout<<max<<endl;
    return 0;
}