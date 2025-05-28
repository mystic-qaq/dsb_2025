#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int, long long> a,pair<int, long long> b){
    return a.second > b.second;
}
int main(){
    int n,k;
    map<int, long long> a,b;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        long long ai,bi;
        cin>>ai>>bi;
        a[i]=ai;
        b[i]=bi;
    }
    vector<pair<int,long long>> v1(a.begin(), a.end());
    sort(v1.begin(),v1.end(),cmp);
    int num=0;
    vector<pair<int,long long>> v2;
    for(auto it = v1.begin();it!=v1.end();++it){
        v2.push_back(make_pair(it->first,b[it->first]));
        num++;
        if(num==k){
            break;
        }
    }
    sort(v2.begin(),v2.end(),cmp);
    auto it=v2.begin();
    cout<<it->first<<endl;
    return 0;
}