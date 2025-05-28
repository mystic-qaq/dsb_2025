#include <bits/stdc++.h>
using namespace std;
struct cnt{
    string object;
    int count;
};
bool ok(char a){
    if((a>='A' and a<='Z') or (a<='z' and a>='a') or(a=='\'')){//这个点有点骚！
        return true;
    }
    else{
        return false;
    }
}
cnt words[1005];
string a[1005];
int main(){
    string ss{};
    int mark{0};
    while(1){
        getline(cin,ss);
        if(ss[0]==0){
            break;
        }//这里不知道为什么稀里糊涂地过了....
        else{
            string st{};
            for(int j=0;j<=ss.length()-1;j++){
                if(ok(ss[j])){
                    st=st+ss[j];
                }
                if(!ok(ss[j]) and st!=""){
                    a[mark]=st;
                    mark++;
                    st="";
                }
            }
            if(st!="")a[mark]=st;
        }
    }
    words[0].object=a[0];
    words[0].count=1;
    int mark2{1};
    bool flag=1;
    for(int i=1;i<=mark;i++){
        flag=1;
        for(int j=0;j<mark2;j++){
            if(a[i]==words[j].object){
                words[j].count++;
                flag=0;
                continue;
            }
        }
        if(flag==1){
            words[mark2].count=1;
            words[mark2].object=a[i];
            mark2++;
        }
    }//这就是标准的统计了，只是不知道STL里是否有可以调用的函数
    for(int i=0;i<=mark2-2;i++){
        cout<<words[i].object<<" "<<words[i].count<<endl;
    }
    return 0;
}   