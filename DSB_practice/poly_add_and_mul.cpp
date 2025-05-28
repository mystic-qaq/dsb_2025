#include <bits/stdc++.h>
using namespace std;
struct node{
    int exp;
    int coef;
};
int k1=0,k2=0,t=0,p=0;
node a[105],b[105];
node addans[105],mulans[205];
bool cmp(node a,node b){
    return a.exp>b.exp;
}
void add(node *a,node *b){
    node temp[205];
    for(int i=0;i<k1;i++){
        temp[i].exp=a[i].exp;
        temp[i].coef=a[i].coef;
    }
    for(int j=0;j<k2;j++){
        temp[k1+j].exp=b[j].exp;
        temp[k1+j].coef=b[j].coef;
    }
    sort(temp,temp+k1+k2,cmp);
    addans[0].exp=temp[0].exp;
    addans[0].coef=temp[0].coef;
    for(int i=1;i<k1+k2;i++){
        if(temp[i].exp==temp[i-1].exp){
            addans[t].coef=addans[t].coef+temp[i].coef;
        }
        else{
            t++;
            addans[t].coef=temp[i].coef;
            addans[t].exp=temp[i].exp;
        }
    }
}
void mul(node *a,node *b){
    int q=0;
    node temp[20005];
    for(int i=0;i<k1;i++){
        for(int j=0;j<k2;j++){
            temp[q].exp=a[i].exp+b[j].exp;
            temp[q].coef=a[i].coef*b[j].coef;
            q++;
        }
    }
    sort(temp,temp+q,cmp);
    mulans[p].coef=temp[0].coef;
    mulans[p].exp=temp[0].exp;
    for(int i=1;i<q;i++){
        if(temp[i].exp==temp[i-1].exp){
            mulans[p].coef=mulans[p].coef+temp[i].coef;
        }
        else{
            p++;
            mulans[p].exp=temp[i].exp;
            mulans[p].coef=temp[i].coef;
        }
    }
}
void printpoly(node *a,int len){
    int startlen=len+1;
    for(int i=0;i<=len;i++){
        if(a[i].coef!=0){
            startlen=i;
            break;
        }
    }
    if(startlen==len+1){
        cout<<0;
    }
    for(int i=startlen;i<=len;i++){
        if(a[i].coef==0){
            continue;
        }
        else if(a[i].exp==0){
            if(a[i].coef>0){
                cout<<'+'<<a[i].coef;
            }
            else{
                cout<<a[i].coef;
            }
        }
        else if(a[i].exp==1){
            if(a[i].coef==1){
                cout<<"+x";
            }
            else if(a[i].coef==-1){
                cout<<"-x";
            }
            else if(a[i].coef>0){
                cout<<'+'<<a[i].coef<<'x';
            }
            else{
                cout<<'-'<<a[i].coef<<'x';
            }
        }
        else if(a[i].coef==-1){
            cout<<"-x^"<<a[i].exp;
        }
        else if(a[i].coef==1){
            cout<<"x^"<<a[i].exp;
        }
        else{
            if(a[i].coef>0 and i!=startlen){
                cout<<'+';
            }
            cout<<a[i].coef<<"x^"<<a[i].exp;
        }
    }
    cout<<endl;
}
int main(){
    int m,n;
    while(cin>>m>>n){
        if(m==0 and n==0){
            break;
        }
        else{
            a[k1].coef=m;
            a[k1].exp=n;
            k1++;
        }
    }
    while(cin>>m>>n){
        if(m==0 and n==0){
            break;
        }
        else{
            b[k2].coef=m;
            b[k2].exp=n;
            k2++;
        }
    }
    add(a,b);
    mul(a,b);
    /*for(int i=0;i<=t;i++){
        cout<<addans[i].coef<<" "<<addans[i].exp<<endl;
    }
    for(int i=0;i<=p;i++){
        cout<<mulans[i].coef<<" "<<mulans[i].exp<<endl;
    }*/
    printpoly(addans,t);
    printpoly(mulans,p);
    return 0;
}