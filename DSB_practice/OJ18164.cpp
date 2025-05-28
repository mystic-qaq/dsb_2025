#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    long long num,ans=0;
    priority_queue<long long,vector<long long>,greater<long long> > q;
    for(int i=1;i<=n;i++){
        cin>>num;
    
        q.push(num);
    }//huffman算法的实现：用一个小根堆，每次合并最小的两个元素，直至合并完成；
    while(!q.empty()){
        if(q.size()==1){
            cout<<ans<<endl;
            q.pop();
        }
        else{
            long long q1=q.top();
            q.pop();
            long long q2=q.top();
            q.pop();
            long long temp=q1+q2;
            q.push(temp);
            ans=ans+temp;
        }
    }
    return 0;
}