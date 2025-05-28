#include<bits/stdc++.h>
using namespace std;
struct bat{
    int num;
    double rate;
};
bool cmp(bat b1,bat b2){
    return b1.rate<b2.rate;//这里值得注意“<”表示升序排列！相当于<时，就往前放。
}
int main(){
    int n;
    double x,y;
    cin>>n;
    bat a[n];
    for(int i=0;i<=n-1;i++){
        cin>>a[i].num>>x>>y;
        a[i].rate=y/x;
    }
    sort(a,a+n,cmp);//sort函数是左开右闭的！并且格式要写成这样！
    int t;
    for(int i=0;i<=n-2;i++){
        if((a[i+1].rate-a[i].rate)>(a[n-1].rate-a[i+1].rate) and (a[i+1].rate-a[i].rate)>(a[i].rate-a[0].rate)){
            t=i;
            break;
        }
    }
    cout<<n-t-1<<endl;
    for(int j=t+1;j<=n-1;j++){
        cout<<a[j].num<<endl;
    }
    cout<<t+1<<endl;
    for(int j=0;j<=t;j++){
        cout<<a[j].num<<endl;
    }
    return 0;
}