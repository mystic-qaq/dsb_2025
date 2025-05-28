#include <bits/stdc++.h>
using namespace std;
struct node{
    char data;
    node *lchild,*rchild;
};
void createtree_preorder(node* &root){
    char c;
    cin>>c;
    if(c=='.'){
        root=NULL;
        return;
    }
    else{
        root=new node;
        root->data=c;
        createtree_preorder(root->lchild);
        createtree_preorder(root->rchild);
    }
}
void preorder(node* T){
    if(T==NULL){
        return;
    }
    else{
        cout<<T->data<<" ";
        preorder(T->lchild);
        preorder(T->rchild);
    }
}
void inorder(node* T){
    if(T==NULL){
        return;
    }
    else{
        inorder(T->lchild);
        cout<<T->data<<" ";
        inorder(T->rchild);
    }
}
void postorder(node* T){
    if(T==NULL){
        return;
    }
    else{
        postorder(T->lchild);
        postorder(T->rchild);
        cout<<T->data<<" ";
    }
}
void createtree_patenses(node* &root,string ss){
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
}
int main(){
    node* T=NULL;
    createtree_preorder(T);
    preorder(T);
    cout<<endl;
    inorder(T);
    cout<<endl;
    postorder(T);
    cout<<endl;
    return 0;
}