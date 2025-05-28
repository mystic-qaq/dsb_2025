#include<bits/stdc++.h>
using namespace std;
int main(){
    string a{};
    getline(cin,a);
    stack<int> st;
    st.push(0);   //括号匹配的常见套路
    for(int i=1;i<=a.length()-1;i++){
        if(a[i]==a[0]){
            st.push(i);
        }
        else{
            cout<<st.top()<<" "<<i<<endl;
            st.pop();
        }
    }
    return 0;
}