#include <bits/stdc++.h>
using namespace std;
int tree[1000005][2];
int pre[1000005],in[1000005],post[1000005];
int mark1,mark2,mark3;
void preorder(int k){
    if(k==0){
        return;
    }
    pre[mark1++]=k;
    preorder(tree[k][0]);
    preorder(tree[k][1]);
}
void inorder(int k){
    if(k==0){
        return;
    }
    inorder(tree[k][0]);
    in[mark2++]=k;
    inorder(tree[k][1]);
}
void postorder(int k){
    if(k==0){
        return;
    }
    postorder(tree[k][0]);
    postorder(tree[k][1]);
    post[mark3++]=k;
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>tree[i][0]>>tree[i][1];
    }
    preorder(1);
    inorder(1);
    postorder(1);
    for(int i=0;i<n;i++){
        if(i==n-1){
            cout<<pre[i]<<endl;
        }
        else{
            cout<<pre[i]<<" ";
        }
    }
    for(int i=0;i<n;i++){
        if(i==n-1){
            cout<<in[i]<<endl;
        }
        else{
            cout<<in[i]<<" ";
        }
    }
    for(int i=0;i<n;i++){
        if(i==n-1){
            cout<<post[i]<<endl;
        }
        else{
            cout<<post[i]<<" ";
        }
    }
    return 0;
}