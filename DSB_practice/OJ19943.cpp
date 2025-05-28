#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int a[n][n]{},d[n][n]{};
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        a[x][y]=1;
        a[y][x]=1;
    }
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=0;j<n;j++){
            sum=sum+a[i][j];
        }
        d[i][i]=sum;
    }
    for(int i=0;i<n;i++){
        cout<<d[i][0]-a[i][0];
        for(int j=1;j<n;j++){
            cout<<" "<<d[i][j]-a[i][j];
        }
        cout<<endl;
    }
    return 0;
}