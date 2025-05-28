#include<bits/stdc++.h>
using namespace std;
struct node{
    char data;
    node* lc;
    node* rc;
};
string ss;
int find(string ss){
    int pos=0;
    stack <char> st;
    if(ss.length()==1){
        return -1;
    }
    for(int i=0;i<=ss.length()-2;i++){
        if(ss[i]=='(' or ss[i]==','){
            st.push(i);
        }
        if(ss[i]==')'){
            if(ss[st.top()]=='('){
                st.pop();
            }
            else{
                st.pop();
                st.pop();
            }
        }
    }
    if(!st.empty() and ss[st.top()]==','){
        pos=st.top();
        return pos;
    }
    else{
        return -1;
    }
}
void buildtree(node* &p,string ss){
    int pos=find(ss);
    if(pos==-1){
        if(ss[0]=='*'){
            p=NULL;
        }
        else{
            p=new node;
            if(ss.length()>3){
                p->data=ss[0];
                p->lc=NULL;
                p->rc=NULL;
                buildtree(p->lc,ss.substr(2,ss.length()-3));
            }
            else{
                p->data=ss[0];
                p->lc=NULL;
                p->rc=NULL;
            }
        }
    }
    else{
        p=new node;
        p->data=ss[0];
        buildtree(p->lc,ss.substr(2,pos-2));
        buildtree(p->rc,ss.substr(pos+1,ss.length()-pos-2));
    }
}   //调了好久之后调出来的终极史山；
void preorder(node *p){
    if(p==NULL){
        return;
    }
    else{
        cout<<p->data;
        preorder(p->lc);
        preorder(p->rc);
    }
}
void inorder(node *p){
    if(p==NULL){
        return;
    }
    else{
        inorder(p->lc);
        cout<<p->data;
        inorder(p->rc);
    }
}
void postorder(node *p){
    if(p==NULL){
        return;
    }
    else{
        postorder(p->lc);
        postorder(p->rc);
        cout<<p->data;
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>ss;
        node *p=new node;
        buildtree(p,ss);
        preorder(p);
        cout<<endl;
        inorder(p);
        cout<<endl;
    }
    return 0;
}