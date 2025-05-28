#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *lchild,*rchild;
};
void preorder(node *root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->lchild);
    preorder(root->rchild);
}
int main(){
    node *root = NULL;
    int n;
    while(scanf("%d",&n)!=EOF){
        node *p = new node;
        p->data = n;
        p->lchild = NULL;
        p->rchild = NULL;
        if(root == NULL){
            root = p;
        }
        else{
            node *temp = root;
            while(temp != NULL){
                if(n < temp->data){
                    if(temp->lchild==NULL){
                        temp->lchild = p;
                        break;
                    }
                    else{
                        temp = temp->lchild;
                    }
                }
                else if(n > temp->data){
                    if(temp->rchild==NULL){
                        temp->rchild = p;
                        break;
                    }
                    else{
                        temp = temp->rchild;
                    }
                }
                else{
                    break;
                }
            }
        }
    }
    preorder(root);
    return 0;
}