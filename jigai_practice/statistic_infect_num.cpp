#include<bits/stdc++.h>
using namespace std;
char a[105][105];
int main(){
    int n,m;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }//如果用1开始的话就会免去边界处理的麻烦！
    cin>>m;
    for(int i=1;i<=m-1;i++){
        char b[105][105]{};//这里避免了一天中重复计数的情形！
        for(int j=1;j<=n;j++){
            for(int l=1;l<=n;l++){
                if(a[j][l]=='@'){
                    if(a[j][l+1]=='.'){
                        b[j][l+1]='@';
                    }
                    if(a[j][l-1]=='.'){
                        b[j][l-1]='@';
                    }
                    if(a[j-1][l]=='.'){
                        b[j-1][l]='@';
                    }
                    if(a[j+1][l]=='.'){
                        b[j+1][l]='@';
                    }
                }
            }     
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(b[i][j]!='\0'){//注意字符数组初始化的值是\0；
                a[i][j]=b[i][j];
                }
            }
        }   
    }
    int infect{0};
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]=='@'){
                infect++;
            }
        }
    }
    cout<<infect<<endl;
    return 0;
}