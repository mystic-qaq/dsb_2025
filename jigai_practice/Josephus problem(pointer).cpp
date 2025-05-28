#include<bits/stdc++.h>
using namespace std;
void Nextperson(bool*b,int&index,int n){
     if(index==n){
        index=1;
     }
     else{
        index++;
     }
     while(b[index]==false){
        if(index==n){
        index=1;
     }
     else{
        index++;
     }
    }
}
int main(){
    int n,m,k;
    bool b[1000]{};
    scanf("%d,%d,%d",&n,&m,&k);
    int index{0};
    for(int i=1;i<=n;i++){
        b[i]=1;
    }
    for(int j=0;j<k;j++){
        for(int i=0;i<m;i++){
            Nextperson(b,index,n);
        }
        b[index]=0;
    }
    cout<<index<<endl;    
    return 0;
}