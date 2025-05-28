#include<bits/stdc++.h>
using namespace std;
int a[300005],l[300005],r[300005];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    a[0]=-2,a[n+1]=-1;//单调栈，哨兵！
    stack<int>st;
    st.push(0);
    for(int i=1;i<=n+1;i++){
        while(!st.empty() and a[i]<=a[st.top()]){
            st.pop();
        }
        l[i]=st.top();
        st.push(i);
    }
    stack<int>sta;
    sta.push(n+1);
    a[0]=-1;a[n+1]=-2;
    for(int i=n;i>=0;i--){
        while(!sta.empty() and a[i]<=a[sta.top()]){
            sta.pop();
        }
        r[i]=sta.top();
        sta.push(i);
    }
    int maxs=0;
    for(int j=1;j<=n;j++){
       maxs=fmax(maxs,(r[j]-l[j]-1)*a[j]);
    }
    cout<<maxs<<endl;
    return 0;
}