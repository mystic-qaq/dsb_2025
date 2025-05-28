#include <bits/stdc++.h>
using namespace std;
int k;
string str,in,post,pre;
void dfs(){
    if(str[k]=='.'){
        k++;
        return;
    }
    char r=str[k];
    k++;
    pre=pre+r;
    dfs();
    in=in+r;
    dfs();
    post=post+r;
}
int main(){
    cin>>str;
    dfs();
    cout<<in<<endl;
    cout<<post<<endl;
    return 0;
}