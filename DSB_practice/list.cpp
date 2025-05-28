#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *next;
};
void create_list(node* &a,int cnt,int m){
    if(cnt==m){
        a=NULL;
        return;
    }
    else{
        a=new node;
        a->data = cnt;
        create_list(a->next,cnt+1,m);
    }
}
int main(){
    int m,n;
    while(cin>>m>>n){
        if(m==0 and n==0){
            return 0;
        }
        else if(n==1){
            for(int i=1;i<=n;i++){
                cout<<i<<" ";
            }
        }
        else{
            node* head = new node;
            create_list(head->next,0,m);
            node* p = head;
            while(p->next!=NULL){
                p = p->next;
            }
            p->next = head->next;
            node* q=head->next;
            int cnt=0;
            while(cnt<=m-1){
                for(int i=1;i<=n-2;i++){
                    q = q->next;
                }
                cout<<q->next->data+1<<" ";
                q->next = q->next->next;
                q = q->next;
                cnt++;
            }  
        }
    }
    return 0;
}