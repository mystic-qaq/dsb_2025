#include<bits/stdc++.h>
using namespace std;
int start[1005],finish[1005];
int main(){
    int j=0,k=0;
    string a,b;
    int ss=0;
    getline(cin,a);
    getline(cin,b);
    for(int i=0;i<=a.length()-1;i++){
        if(a[i]==','){
            start[j]=int(ss);
            ss=0;
            j++;
        }
        else{
            ss=10*ss+int(a[i]-'0');
        }
    }
    start[j]=ss;
    ss=0;
    for(int i=0;i<=b.length()-1;i++){
        if(b[i]==','){
            finish[k]=int(ss);
            ss=0;
            k++;
        }
        else{
            ss=10*ss+int(b[i]-'0');
        }
    }
    finish[k]=ss;
    cout<<k+1<<" ";
    int busy=0;
    for(int i=0;i<1000;i++){
        int count=0;
        for(int l=0;l<=k+1;l++){
            if(i>=start[l] and i+1<=finish[l]){
                count++;
            }
        }
        busy=fmax(count,busy);
    }
    cout<<busy<<endl;
    return 0;
}