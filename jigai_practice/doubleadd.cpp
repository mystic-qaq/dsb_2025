#include<bits/stdc++.h>
using namespace std;
string bigadd(string num1,string num2){
    int len=num1.length()-num2.length();
    if(len>0){
        string ss(len,'0');       //构建一个字符串的方法；
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
        ans="1"+ans; 
    }
    return ans;
}
string doubleadd(string a,string b){
    int len1,len2,mark1,mark2;
    for(int i=0;i<=a.length()-1;i++){
        if(a[i]=='.'){
            len1=a.length()-1-i;
            mark1=i;
            break;
        }
    }
    for(int i=0;i<=b.length()-1;i++){
        if(b[i]=='.'){
            len2=b.length()-1-i;
            mark2=i;
            break;
        }
    }
    if(len1<len2){
        a=a+string(len2-len1,'0');
    } 
    else{
        b=b+string(len1-len2,'0');///记住了，不要再弄反了！！！！！
    }
    string ans=bigadd(a.substr(0,mark1)+a.substr(mark1+1,a.length()-1-mark1),b.substr(0,mark2)+b.substr(mark2+1,b.length()-1-mark2));
    int mark=max(mark1,mark2);
    int len=ans.length()+1;
    ans=ans.substr(0,mark)+"."+ans.substr(mark,len-mark-1);
    return ans;
}
string removeZeros(string a){
    int mark;
    for(int i=a.length()-1;i>=0;i--){
        if(a[i]!='0'){
            mark=i+1;
            break;
        }
        
    }
    a=a.substr(0,mark);
    return a;
}
int main(){
    int n;
    cin>>n;
    getchar();
    for(int i=1;i<=n;i++){
        string a,b,ans;
        getline(cin,a);
        getline(cin,b);
        ans=removeZeros(doubleadd(a,b));
        cout<<ans<<endl;
        getchar();//一个小细节，要把回车吞掉。
    }
    return 0;
}