#include<bits/stdc++.h>
using namespace std;
long long dep[55];
int main(){
    dep[0]=0,dep[1]=1;
    for(int i=2;i<=50;i++){
        dep[i]=dep[i-1]+dep[i-2]+1;
    }
    int n;
    cin>>n;
    cout<<dep[n]<<endl;
    return 0;
}