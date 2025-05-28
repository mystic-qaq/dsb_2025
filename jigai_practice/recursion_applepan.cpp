#include<bits/stdc++.h>
using namespace std;
int f(int apple,int pan){
    if(apple==0 or pan==1){
        return 1;
    }
    else if(apple<pan){
        return f(apple,apple);
    }
    else{
        return f(apple,pan-1)+f(apple-pan,pan);
    }
}
int main(){
    int n,apple,pan;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>apple>>pan;
        cout<<f(apple,pan)<<endl;
    }
    return 0;
}