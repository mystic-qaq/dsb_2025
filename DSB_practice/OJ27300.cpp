#include <bits/stdc++.h>
using namespace std;
struct machine{
    string name;
    string volume;
};
int f(string ss){
    for(int i=0;i<ss.length()-1;i++){
        if(ss[i]=='.'){
            return i;
        }
    }
    return ss.length()-1;
}
bool cmpint(string a,string b){
    if(a.length()>b.length()){
        string ss=string(a.length()-b.length(),'0');
        b=ss+b;
    }
    else{
        string ss=string(b.length()-a.length(),'0');
        a=ss+a;
    }
    return a<b;
}
bool cmp(string a,string b){
    if(a[a.length()-1]!=b[b.length()-1]){
        return a[a.length()-1]>b[b.length()-1];
    }
    else{
        int amark=f(a),bmark=f(b);
        string a1=a.substr(0,amark),b1=b.substr(0,bmark);
        if(a1!=b1){
            return cmpint(a1,b1);
        }
        else{
            if(amark==a.length()){
                if(bmark==b.length()){
                    return false;
                }
                else{
                    return true;
                }
            }
            else{
                if(bmark==b.length()){
                    return false;
                }
                else{
                    string a2=a.substr(amark+1,a.length()-amark-2),b2=b.substr(bmark+1,b.length()-2-bmark);
                    if(a2.length()>b2.length()){
                        string ss=string(a2.length()-b2.length(),'0');
                        b2=b2+ss;
                    }
                    else{
                        string ss=string(b2.length()-a2.length(),'0');
                        a2=a2+ss;
                    }
                    return cmpint(a2,b2);
                }
            }
        }
    }
}
bool cmp1(machine a,machine b){
    return a.name<b.name;
}
bool cmp2(machine a,machine b){
    return cmp(a.volume,b.volume);
}
machine a[1005];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int mark=0;
        string ss;
        cin>>ss;
        while(ss[mark]!='-'){
            mark++;
        }
        a[i].name=ss.substr(0,mark);
        a[i].volume=ss.substr(mark+1,ss.length()-1-mark);
        //cout<<a[i].name<<endl<<a[i].volume<<endl;
    }
    sort(a+1,a+n+1,cmp1);
    int start=1,end=1;
    for(int i=2;i<=n+1;i++){
        start=end;
        if(i==n+1){
            end=n+1;
            sort(a+start,a+end,cmp2);
            cout<<a[start].name<<": "<<a[start].volume;
        }
        else if(a[i].name!=a[i-1].name){
            end=i;
            sort(a+start,a+end,cmp2);
            cout<<a[start].name<<": "<<a[start].volume;
        }
        if(end==start+1){
            cout<<endl;
        }
        for(int j=start+1;j<end;j++){
            cout<<", "<<a[j].volume;
            if(j==end-1){
                cout<<endl;
            }
        } 
    }    
    return 0;
}