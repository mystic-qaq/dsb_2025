#include<bits/stdc++.h>
using namespace std;
int f(int x,int n){
    if(x==0){
        return 0;
    }
    else{
        return n*f(x/10,n)+x%10;
    }
}//递归是进制转化的一个办法；
int main(){
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int p,q,r,p1,q1,r1;
        int flag=0;
        cin>>p>>q>>r;
        p1=p;
        q1=q;
        r1=r;
        int max{0};
        while(p>0){
            max=fmax(p%10,max);
            p=p/10;
        }
        while(q>0){
            max=fmax(q%10,max);
            q=q/10;
        }
        while(r>0){
            max=fmax(r%10,max);
            r=r/10;
        }//这里要注意有个大坑，进制是一定比任何一位都大的！
        for(int j=max+1;j<=16;j++){
            if(f(p1,j)*f(q1,j)==f(r1,j)){
                cout<<j<<endl;
                flag=1;
                break;
            }
        }
        if(flag==0){
            cout<<0<<endl;
        }
    }
    return 0;
}