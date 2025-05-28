#include <bits/stdc++.h>
using namespace std;
int main(){
    char a[1001]{};
    cin.getline(a,1001);//注意这里不能用cin，否则遇到空格即停；这是一种新的字符串读入方式；
    int num1{0},num2{0};
    for(int i=0;i<=1000;i++){
        if(a[i]=='*'){
            num1++;
        }
        if(a[i]=='@'){
            num2++;
        }
    }
    printf("*出现了%d次;\n",num1);
    printf("@出现了%d次.\n",num2);
    return 0;
}
    

