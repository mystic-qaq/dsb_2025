#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int m=b*d;
    int n=a*d+b*c;
    int l=__gcd(m,n);
    cout<<n/l<<"/"<<m/l<<endl;
    return 0;
}  //面向对象的写法还要去学；