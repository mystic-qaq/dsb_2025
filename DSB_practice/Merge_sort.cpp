#include <bits/stdc++.h>
using namespace std;
int ans=0;
int a[100005],temp[100005];
void merge(int *a,int *temp,int start,int mid,int end){
    int i=start,j=mid+1,k=start;
    while(i!=mid+1 and j!=end+1){
        if(a[i]>a[j]){
            ans=ans+j-k;
            temp[k]=a[j];
            k++;
            j++;
        }
        else{
            temp[k]=a[i];
            k++;
            i++;
        }
    }
    while(i!=mid+1){
        temp[k]=a[i];
        k++;
        i++;
    }
    while(j!=end+1){
        temp[k]=a[j];
        k++;
        j++;
    }
    for(int i=start;i<=end;i++){
        a[i]=temp[i];
    }
}
void merge_sort(int *a,int start,int end){
    if(start<end){
        int mid=(start+end)/2;
        merge_sort(a,start,mid);
        merge_sort(a,mid+1,end);
        merge(a,temp,start,mid,end);
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    merge_sort(a,1,n);
    for(int i=1;i<=n;i++){
        cout<<a[i]<<endl;
    }
    cout<<ans<<endl;
    return 0;
}