#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    priority_queue <int,vector<int>,greater<int> > q;
    for(int i=1;i<=n;i++){
        int type,num;
        cin>>type;
        if(type==1){
            cin>>num;
            q.push(num);
        }
        else{
            cout<<q.top()<<endl;
            q.pop();
        }
    }
    return 0;
}