#include <bits/stdc++.h>
using namespace std;
struct node{
    char data;
    node *lchild,*rchild;
};
void createtree(node* &root,string ss){
    stack <node*> st;
    int flag=0;
    int index=0;
    char c=ss[index];
    node *p;
    while(index<ss.length()){
        c=ss[index];
        if(c=='('){
            st.push(p);
            flag=1;
        }
        else if(c==')'){
            st.pop();
        }
        else if(c==','){
            flag=2;
        }
        else{
            p=new node;
            if(c=='*'){
                p=NULL;
                if(flag==1){
                    st.top()->lchild=p;
                }
                else{
                    st.top()->rchild=p;
                }
            }
            else{
                p->data=c;
                p->lchild=NULL;
                p->rchild=NULL;
                if(root==NULL){
                    root=p;
                }
                else{
                    if(flag==1){
                        st.top()->lchild=p;
                    }
                    else{
                        st.top()->rchild=p;
                    }
                }  
            }        
        }
        index++;
    }
}  //处理括号一个很好的思路就是使用栈，当然这个题似乎写的有些复杂了；
void preorder(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data;
    preorder(root->lchild);
    preorder(root->rchild);
}
void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->lchild);
    cout<<root->data;
    inorder(root->rchild);
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        string ss;
        cin>>ss;
        node *root=NULL;
        createtree(root,ss);
        preorder(root);
        cout<<endl;
        inorder(root);
        cout<<endl;
    }
    return 0;
}