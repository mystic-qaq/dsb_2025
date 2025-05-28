#include <bits/stdc++.h>
using namespace std;
int main(){
    int n{0};
    cin>>n;
    for(int j=1;j<=n;j++){
        string num1,num2;
        cin>>num1>>num2;
        int len=num1.length()-num2.length();
     if(len>0){
        string ss(len,'0');       //构建一个字符串的方法，简单而愉快；
        num2=ss+num2;
     }
     else if(len<0){
        string ss(-len,'0');
        num1=ss+num1;
     }
        string ans=num1;
        int mod{0};
        for(int i=num1.length()-1;i>=0;i--){
        ans[i]=((num1[i]-'0')+(num2[i]-'0')+mod)%10+'0'; //注意要减‘0’，这是ASCII码！！！！
        mod=((num1[i]-'0')+(num2[i]-'0')+mod)/10;
        }
        if(mod!=0){
        ans='1'+ans;
        }
        cout<<ans<<endl;
    }
    return 0;
}