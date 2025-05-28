#include<bits/stdc++.h>
using namespace std;
int main(){
    string ss{};
    while(getline(cin,ss)){
        long long num=0;
        bool flag=1,flag1=1;
        stack<long long> a;
        for(int i=0;i<=ss.length()-1;i++){
            if(ss[i]<='9' and ss[i]>='0'){
                num=num*10+(ss[i]-'0');
                flag=0;
            }         //这题还有一个关键点，即如何处理输入
            if(ss[i]==' ' and flag==0){
                a.push(num);
                num=0;
                flag=1;
            }
            if(ss[i]=='-'){
                flag=1;
                long long c,d;
                d=a.top();a.pop();
                c=a.top();a.pop();
                c=c-d;
                a.push(c);
            }
            if(ss[i]=='+'){
                flag=1;
                long long c,d;
                d=a.top();a.pop();
                c=a.top();a.pop();
                c=c+d;
                a.push(c);
            }
            if(ss[i]=='*'){
                flag=1;
                long long c,d;
                d=a.top();a.pop();
                c=a.top();a.pop();
                c=c*d;
                a.push(c);
            }
            if(ss[i]=='/'){
                flag=1;
                long long c,d;
                d=a.top();a.pop();
                c=a.top();a.pop();
                if(d==0){
                    cout<<"NaN"<<endl;
                    flag1=0;
                    break;
                }
                else{
                    c=c/d;
                    a.push(c);
                }
            }
            if(ss[i]=='@'){
                flag=1;
                break;
            }
        }
        if(flag1==1){
            cout<<a.top()<<endl;
            a.pop();
        }        //注意不要重复输出（这是可以动态查错查出来的）！
    }
    return 0;
}