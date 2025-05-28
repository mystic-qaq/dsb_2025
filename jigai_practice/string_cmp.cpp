#include<bits/stdc++.h>
using namespace std;
bool cmp(string a,string b){
    return a+b>b+a;//两个字符串是可以直接比较的，（已经内置了），这其实就相当于把更优的放到前面；
}
int main(){
    int n;
    cin>>n;
    string a[n];
    for(int i=0;i<=n-1;i++){
        cin>>a[i];
    }
    sort(a+0,a+n,cmp);
    string s="";
    for(int i=0;i<=n-1;i++){
        s=s+a[i];
    }
    cout<<s<<endl;
    return 0;
}