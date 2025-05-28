#include <bits/stdc++.h>
using namespace std;
int main(){
    string ss{};
    while(getline(cin,ss)){
        stack<int> st{};
        string ans{};
        for(int i=0;i<=ss.length()-1;i++){
            if(ss[i]=='('){
                st.push(i);
            }
            if(ss[i]==')'){
                if(!st.empty()){
                    if(ss[st.top()]=='('){
                        st.pop();
                    }
                    else{
                        st.push(i);
                    }
                }
                else{
                    st.push(i);
                }
            }
        }
        for(int i=ss.length()-1;i>=0;i--){
                if(ss[i]=='('){
                    if(!st.empty() and st.top()==i){
                        ans='$'+ans;
                        st.pop();
                    }
                    else{
                        ans=' '+ans;
                    }
                }
                else if(ss[i]==')'){
                    if(!st.empty() and st.top()==i){
                        ans='?'+ans;
                        st.pop();
                    }
                    else{
                        ans=' '+ans;
                    }
                }
                else{
                    ans=' '+ans;
                }
        }
        cout<<ss<<endl;
        cout<<ans<<endl;
        }
    
    return 0;
}