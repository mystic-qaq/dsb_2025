#include<bits/stdc++.h>
using namespace std;
struct node{
    int x,y;
    bool operator==(const node &other) const{
        return (x == other.x and y == other.y);
    }
};  //主要是学习运算重载符的使用
struct Myfuction{
   size_t operator()(const node &n) const {
        return hash<int>()(n.x)^(hash<int>()(n.y) << 1);
   }
}; //hash_map 需要构建一个hash值，上面是一个两值的常用办法...
node a[1005];
int main(){
    int k;
    while(cin>>k){
        if(k==0){
            break;
        }
        else{
            unordered_map<node,bool,Myfuction> mp;
            for(int i=1;i<=k;i++){
                cin>>a[i].x>>a[i].y;
                mp[node{a[i].x,a[i].y}] = 1;
            }
            int cnt = 0;
            for(int i=1;i<=k;i++){
                for(int j=i+1;j<=k;j++){
                    int x1,y1,x2,y2;
                    x1 = a[i].x;
                    y1 = a[i].y;
                    x2 = a[j].x;
                    y2 = a[j].y;
                    if(mp.count(node{x2+y1-y2,y2+x2-x1}) and mp.count(node{x1+y1-y2,y1+x2-x1})){
                        cnt++;
                    }
                    if(mp.count(node{x2+y2-y1,y2+x1-x2}) and mp.count(node{x1+y2-y1,y1+x1-x2})){
                        cnt++;
                    }
                }
            }
            cout<<cnt/4<<endl;
        }
    }
    return 0;
}