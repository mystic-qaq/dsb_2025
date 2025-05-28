#include<bits/stdc++.h>
using namespace std;
int a[20];
int t,n;
bool flag{0};
void dfs(int w,int t){//这个题目比较值得注意的点是特判，动态debug时应当尤其注意这些
    if(t==1){
        flag=1;
        return;
    }
    if(w==n+1){
        return;
    }
    if(t!=1){
        if(a[w]!=0){
            if(t%a[w]==0){
                dfs(w+1,t/a[w]);
            }
        }
        dfs(w+1,t);
    }
}
int main(){
    cin>>t>>n;
    if(n==0){
        cout<<"NO"<<endl;
        return 0;
    }
    else{
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        if(t==0){
            for(int i=1;i<=n;i++){
                if(a[i]==0){
                    cout<<"YES"<<endl;
                    return 0;
                }
            }
            cout<<"NO"<<endl;
            return 0;
        }
        else{
            dfs(1,t);
            if(flag==1){
                cout<<"YES"<<endl;
                return 0;
            }
            else{
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
}