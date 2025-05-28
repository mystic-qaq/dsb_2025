#include<bits/stdc++.h>
using namespace std;
bool x[100005]{};
int a[50005],b[50005];
int main(){
    int n,num1{0},num2{0};
    cin>>n;
    for(int i=0;i<=n-1;i++){
        cin>>a[i]>>b[i];
    }
    sort(a,a+n);
    sort(b,b+n);
    for(int i=a[0];i<=b[n-1];i++){
        num1=0,num2=0;
        for(int j=0;j<=n-1;j++){
            if(a[j]<float(i+0.5)){
                num1++;
            }
            else{
                break;
            }
        }
        for(int j=0;j<=n-1;j++){
            if(b[j]<float(i+0.5)){
                num2++;
            }
            else{
                break;
            }
        }
        if(num1==num2){
            x[i]=1;
        }
    }
    x[b[n-1]]=0;
    bool flag{0},flagx{0};
    for(int i=a[0];i<=b[n-1];i++){
        if(x[i] and flag==0){
            cout<<i<<" ";
            flag=1;
            flagx=1;
        }
        if(flag==1 and !x[i]){
            cout<<i<<endl;
            flag=0;
        }
    }
    if(flagx==0){
        cout<<"Not Needed"<<endl;
    }
    return 0;
}