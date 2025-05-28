#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    int R,n;
    while(cin>>R>>n){
        if(R==-1 and n==-1){
            return 0;
        }
        else{
            int a[n]{},cnt{0},mark{0},top{0};
            for(int i=0;i<=n-1;i++){
                cin>>a[i];
            }
            sort(a+0,a+n,cmp);
            while(mark<=n-1){
                if(a[mark]-R<=a[n-1]){
                    cnt++;
                }//这里是一个小细节；在后面的循环中如果找不到i，就不会再加了，所以要补充情况。
                for(int i=mark;i<=n-1;i++){
                    if(a[mark]-R>a[i]){
                        mark=i-1;
                        cnt++;
                        break;
                    }
                }
                top=a[mark]-R;
                if(top<=a[n-1]){
                    break;
                }
                else{
                    for(int i=mark;i<=n-1;i++){
                        if(a[i]<top){
                            mark=i;
                            break;
                        }
                    }
                }
            }
            cout<<cnt<<endl;
        }
    }
    return 0;
}