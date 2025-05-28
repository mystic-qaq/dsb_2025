#include <bits/stdc++.h>
using namespace std;
int main(){
    int m{0},n;
    cin>>n;
    for(int i=1;i<=n;i++){
        string a;
        float x;
        int y;
        cin>>a>>x>>y;//灵活变通！！
        if(x>=37.5 and y==1){
            cout<<a<<endl;
            m++;
        }
    }
    cout<<m<<endl;
    return 0;
}
