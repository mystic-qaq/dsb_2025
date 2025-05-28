#include<bits/stdc++.h>
using namespace std;
int a[100005],b[10005];
int main(){
    int n,m;
    cin>>n>>m;
    int fullcnt{0},appcnt{0};
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        if(b[a[i]]==fullcnt){
            b[a[i]]++;
            appcnt++;
        }
        if(appcnt==m){
            fullcnt++;
            appcnt=0;
        }
    }
    cout<<fullcnt+1<<endl;
    return 0;
}