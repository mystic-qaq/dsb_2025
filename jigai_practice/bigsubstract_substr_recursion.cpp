#include<bits/stdc++.h>
using namespace std;
string removezeros(string s1){
    string s="";
    for(int i=0;i<s1.length();i++){
        if(s1[i]=='0'){
            continue;
        } else {
            s=s1.substr(i,s1.length()-i);//s1.substr():从下标为i的元素开始，取s1.length()-i位；
            break;
        }
    }
    if(s==""){
        return "0";
    } else {
        return s;
    }
}
string bigadd(string num1,string num2){
    int len=num1.length()-num2.length();
    if(len>0){
        string ss(len,'0');
        num2=ss+num2;
    }
    else if(len<0){
        string ss(-len,'0');
        num1=ss+num1;
    }
    string ans=num1;
    int mod{0};
    for(int i=num1.length()-1;i>=0;i--){
        ans[i]=((num1[i]-'0')+(num2[i]-'0')+mod)%10+'0'; 
        mod=((num1[i]-'0')+(num2[i]-'0')+mod)/10;
    }
    if(mod!=0){
        ans='1'+ans;
    }
    return ans;
}
string bigsubstract(string num1,string num2){
    int len=num1.length()-num2.length();
    if(len>0){
        string ss(len,'0');
        num2=ss+num2;
    }
    else if(len<0){
        string ss(-len,'0');
        num1=ss+num1;
    }
    string ans=num1;
    int mod{0};
    for(int i=num1.length()-1;i>=0;i--){
        ans[i]=((num1[i]-'0')-(num2[i]-'0')-mod+10)%10+'0';
        if((num1[i]-'0')-(num2[i]-'0')-mod<0){
            mod=1;
        }
        else{
            mod=0;
        } 
    }
    if(mod==0){
        ans=removezeros(ans);
        return ans;
    }
    else if(mod==1){
        return '-'+removezeros(bigsubstract(num2,num1));//recursion application!
    }
    else{
        return " ";
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        string s1,s2;
        cin>>s1>>s2;
        string s;
        bool s1neg{0},s2neg{0};
        if(s1[0]=='-'){
            s1neg=1;
            s1=s1.substr(1,s1.length()-1);
        }
        if(s2[0]=='-'){
            s2neg=1;
            s2=s2.substr(1,s2.length()-1);
        }
        if(s1[0]=='+'){
            s1=s1.substr(1,s1.length()-1);
        }
        if(s2[0]=='+'){
            s2=s2.substr(1,s2.length()-1);
        }
        if(s1neg and s2neg){
            cout<<bigsubstract(s2,s1)<<endl;
        }
        if(s1neg and !s2neg){
            cout<<"-"<<bigadd(s1,s2)<<endl;
        }
        if(!s1neg and s2neg){
            cout<<bigadd(s1,s2)<<endl;
        }
        if(!s1neg and !s2neg){
            cout<<bigsubstract(s1,s2)<<endl;
        }    
    }
    return 0;
}