#include<bits/stdc++.h>
using namespace std;
int a,b,c,vis[105][105],ans;
string p[105][105],ansofp;
bool flag;
struct node{
    int x,y;
    string path;
};
node operate(int i,node n){
    if(i==1){
        n.x=a;
        n.path=n.path+'1';
    }
    else if(i==2){
        n.y=b;
        n.path=n.path+'2';
    }
    else if(i==3){
        n.x=0;
        n.path=n.path+'3';
    }
    else if(i==4){
        n.y=0;
        n.path=n.path+'4';
    }
    else if(i==5){
        if(n.x>=b-n.y){
            n.x=n.x-b+n.y;
            n.y=b;
        }
        else{
            n.y=n.y+n.x;
            n.x=0; 
        }
        n.path=n.path+'5';
    }
    else{
        if(n.y>=a-n.x){
            n.y=n.y-a+n.x;
            n.x=a;
        }
        else{
            n.x=n.x+n.y;
            n.y=0;
        }
        n.path=n.path+'6';
    }
    return n;
}
void bfs(){
    queue<node> q;
    q.push({0,0});
    vis[0][0]=1;
    while(!q.empty()){
        for(int i=1;i<=6;i++){
            node n=operate(i,q.front());
            if(vis[n.x][n.y]==0){
                vis[n.x][n.y]=vis[q.front().x][q.front().y]+1;
                p[n.x][n.y]=n.path;
                q.push(n);
            }
            else{
                continue;
            }
            if(n.x==c or n.y==c){
                flag=1;
                break;
            }
        }
        if(flag==1){
            ans=vis[q.back().x][q.back().y]-1;
            ansofp=p[q.back().x][q.back().y];
            break;
        }
        q.pop();
    }
}   //一个非常新颖的bfs
int main(){
    cin>>a>>b>>c;
    bfs();
    if(flag==0){
        cout<<"impossible"<<endl;
    }
    else{
        cout<<ans<<endl;
        for(int i=0;i<=ansofp.length()-1;i++){
            if(ansofp[i]=='1'){
                cout<<"FILL(1)"<<endl;
            }
            else if(ansofp[i]=='2'){
                cout<<"FILL(2)"<<endl;
            }
            else if(ansofp[i]=='3'){
                cout<<"DROP(1)"<<endl;
            }
            else if(ansofp[i]=='4'){
                cout<<"DROP(2)"<<endl;
            }
            else if(ansofp[i]=='5'){
                cout<<"POUR(1,2)"<<endl;
            }
            else{
                cout<<"POUR(2,1)"<<endl;
            }
        }
    }
    return 0;
}