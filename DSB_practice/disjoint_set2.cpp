#include<bits/stdc++.h>
using namespace std;
int pre[100005];
int depth(int k){
    int d = 0;
    while(pre[k] != 0){
        k = pre[k];
        d++;
    }
    return d;
}
int findroot(int k){
    while(pre[k]!=0){
        k = pre[k];
    }
    return k;
}
void trans(int k){
    int k1 = k;
    if(pre[k] == 0)return;
    else{
        stack<int> st;
        while(k != 0){
            st.push(k);
            k = pre[k];
        }
        while(st.size() >= 2){
            int temp = st.top();
            st.pop();
            pre[temp] = st.top();
        }
        pre[k1] = 0;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        memset(pre,0,sizeof(pre));
        int m,n;
        cin>>n>>m;
        char a;
        int x,y;
        for(int i=1;i<=m;i++){
            cin>>a>>x>>y;
            if(a == 'A'){
                if(findroot(x) != findroot(y)){
                    cout<<"Not sure yet."<<endl;
                }
                else{
                    int t = depth(x) - depth(y);
                    if(t % 2 == 0){
                        cout<<"In the same gang."<<endl;
                    }
                    else{
                        cout<<"In different gangs."<<endl;
                    }
                }
            }
            else{
                int xroot = findroot(x), yroot = findroot(y);
                if(xroot != yroot){
                    trans(x);
                    trans(y);
                    pre[y] = x;
                }
            }
        }
    }
    return 0;
}