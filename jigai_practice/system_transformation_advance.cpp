#include<bits/stdc++.h>
using namespace std;
int f(string x,int n){
    if(x.length()==1){
        if(x[0]>='a'){
            return int(x[0]-'a'+10);
        }
        else{
            return int(x[0]-'0');
        }

    }
    else{
        if(x[x.length()-1]>='a'){
            return n*f(x.substr(0,x.length()-1),n)+int(x[x.length()-1]+10-'a');
        }
        else{
            return n*f(x.substr(0,x.length()-1),n)+int(x[x.length()-1]-'0');
        }
    }
}
string g(int x,int n){
    string ss{};
    while(x>0){
        if(x%n<=9){
            ss=char(x%n+'0')+ss;
            x=x/n;
        }
        else{
            ss=char(x%n-10+'a')+ss;
            x=x/n;
        }
    }
    return ss;
}
int main(){
    int n1,n2,n3,sum10;
    string ans,x1,x2;
    cin>>n1>>x1>>n2>>x2>>n3;
    sum10=f(x1,n1)+f(x2,n2);
    cout<<g(sum10,n3)<<endl;
    return 0;
}