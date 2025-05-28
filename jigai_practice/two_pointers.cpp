#include <bits/stdc++.h>
using namespace std;
int a[1005];
bool cmp(int a,int b){
	return a<b;
}
int main(){
	int n,ans=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
	sort(a,a+n,cmp);
    int len = unique(a,a+n) - a;
	//-40 -10 0 10 20;
    for(int i=0;i<=len-1;i++){
        int l=i+1,r=len-1;
        while(l<r){
            if(a[i]+a[r]+a[l]==0){
                ans++;
                l++;
                r--;
            }
            else if(a[i]+a[l]+a[r]>0){
                r--;
            }
            else{
                l++;
            }
        }
    }
    cout<<ans<<endl;
	return 0;
}