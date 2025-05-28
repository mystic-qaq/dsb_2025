#include <bits/stdc++.h>
using namespace std;
struct node{
    char data;
    node *l,*r;
};
struct temp{
    int depth;
    node *n;
    bool flag;
};
void preorder(node *root){
    if(root == NULL or root->data == '*'){
        return;
    }
    cout<<root->data;
    preorder(root->l);
    preorder(root->r);
}
void inorder(node *root){
    if(root == NULL or root->data == '*'){
        return;
    }
    inorder(root->l);
    cout<<root->data;
    inorder(root->r);
}
void postorder(node *root){
    if(root == NULL or root->data == '*'){
        return;
    }
    postorder(root->l);
    postorder(root->r);
    cout<<root->data;
}
int main(){
    node *root = new node;
    string ss;
    stack<temp> st;
    while(cin>>ss){
        if(ss == "0"){
            preorder(root);
            cout<<endl;
            postorder(root);
            cout<<endl;
            inorder(root);
            return 0;
        }
        else{
            int depth = ss.length()-1;
            char data = ss[ss.length()-1];
            if(depth == 0){
                root->data = data;
                root->l = NULL;
                root->r = NULL;
                st.push(temp{depth,root,false});
            }
            else{
                temp t = st.top();
                st.pop();
                while(t.depth >= depth){
                    t = st.top();
                    st.pop();
                }
                if(t.flag == false){
                    node *s = new node;
                    s->data = data;
                    s->l = NULL;
                    s->r = NULL;
                    t.n->l = s;
                    st.push(temp{t.depth, t.n, true});
                    st.push(temp{depth, s, false});
                }
                else{
                    node *s = new node;
                    s->data = data;
                    s->l = NULL;
                    s->r = NULL;
                    t.n->r = s;
                    st.push(temp{depth, s, false});
                }
            }
        }
    }
    return 0;
}