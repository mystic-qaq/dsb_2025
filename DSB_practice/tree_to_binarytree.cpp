#include<bits/stdc++.h>
using namespace std;
struct node{
    char data;
    node *son;
    node *bro;
};
void preorder(node *root){
    if(root == NULL){
        return;
    }
    else{
        cout<<root->data;
        preorder(root->son);
        preorder(root->bro);
    }
}
void postorder(node *root){
    if(root ==NULL)return;
    else{
        postorder(root->son);
        postorder(root->bro);
        cout<<root->data;
    }
}
node* a[30];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        a[i] = new node;
        a[i]->bro = NULL;
        a[i]->son = NULL;
    }
    for(int i=1;i <= n;i++){
        char c;
        cin>>c;
        a[i]->data = c;
        int m;
        bool flag = false;
        node *temp = NULL;
        while(cin>>m){
            if(m==0 and flag == false){
                a[i]->son = NULL;
                break;
            }
            else if(m==0 and flag == true){
                temp->bro = NULL;
                break;
            }
            else{
                if(flag == false){
                    a[i]->son = a[m];
                    temp = a[m];
                    flag = true;
                }
                else{
                    temp->bro = a[m];
                    temp = a[m];
                }
            }
        }
    }
    preorder(a[1]);
    cout<<endl;
    postorder(a[1]);
    return 0;
}