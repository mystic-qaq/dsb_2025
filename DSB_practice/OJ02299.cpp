#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,ans;
ll a[500005],b[500005];
void merge(ll a[],ll l,ll r){
    if(l>=r){
        return;
    }
    ll mid=(l+r)/2;
    merge(a,l,mid);
    merge(a,mid+1,r);
    ll i=l,j=mid+1;
    for(ll k=l;k<=r;k++){
        if(j>r or i<=mid and a[i]<=a[j]){
            b[k]=a[i];
            i++;
        }
        else{
            ans=ans+mid-i+1;
            b[k]=a[j];
            j++;
        }
    }
    for(ll k=l;k<=r;k++){
        a[k]=b[k];
    }
}   //归并排序适合处理逆序对的个数
int main(){
    while(cin>>n){
        if(n==0){
            return 0;
        }
        else{
            for(ll i=1;i<=n;i++){
                cin>>a[i];
            }
            ans=0;
            merge(a,1,n);
            cout<<ans<<endl;
        }
    }
    return 0;
}