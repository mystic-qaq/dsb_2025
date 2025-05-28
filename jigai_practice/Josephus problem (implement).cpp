#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,k;
    scanf("%d,%d,%d",&n,&m,&k);
    int count=0,removed=0;
    bool students[1000]{};
    int i=1;
    while(1){
       if(students[i]==1){
        i=(i+1)%n;
        continue;
       }
       count++;
       if(count==m){
        students[i]=1;
        count=0;
        removed++;
       }
       if(removed==k){
          break;
       }
       i=(i+1)%n;//这里要更新自己先前对循环的认知！
    }
    if(i==0){
        i=n;
    }
    cout<<i<<endl;
    return 0;//大模拟题，模拟出情况即可！
}