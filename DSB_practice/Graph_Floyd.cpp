#include<bits/stdc++.h>
using namespace std;
struct dict
{
    int len;
    int pre;
};
//Floyd单元最短寻路？
dict D[35][35];
map <string,int> M1;
map <int,string> M2;
string s1,s2;
void Print(int start,int end){
    if(start==end){
        cout<<M2[end];
        return;
    }
    Print(start, D[start][end].pre);
    cout<<"->("<<D[D[start][end].pre][end].len<<")->"<<M2[end];
}
int main(){
    int n,m,dis;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>s1;
        M1[s1] = i;
        M2[i] = s1;
    }
    cin>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                D[i][j].len=0;
                D[i][j].pre=i;
            }
            else{
                D[i][j].len = 0x3f3f3f3f;
                D[i][j].pre = -1;
            }

        }
    }
    for(int i=0;i<m;i++){
        cin>>s1>>s2>>dis;
        if(D[M1[s1]][M1[s2]].len>dis){
            D[M1[s1]][M1[s2]].len = dis;
            D[M1[s1]][M1[s2]].pre = M1[s1];
        }
        if(D[M1[s2]][M1[s1]].len>dis){
            D[M1[s2]][M1[s1]].len=dis;
            D[M1[s2]][M1[s1]].pre=M1[s2];
        }
    }
    for(int t=0;t<n;t++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(D[i][t].len+D[t][j].len<D[i][j].len){
                    D[i][j].len=D[i][t].len+D[t][j].len;
                    D[i][j].pre=D[t][j].pre;
                }
            }
        }
    }
    int t;
    cin>>t;
    while(t--){
        cin>>s1>>s2;
        Print(M1[s1],M1[s2]);
        cout<<endl;
    }
    return 0;
}
