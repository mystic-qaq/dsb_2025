#include<bits/stdc++.h>
using namespace std;
int a[100005];
int part_sort(int* a,int start,int end){
    int pivot=a[start];
    while(start<end){
        while(start<end and a[end]>=pivot){
            end--;
        }
        a[start]=a[end];
        while(start<end and a[start]<=pivot){
            start++;
        }
        a[end]=a[start];
    }
    a[start]=pivot;
    return start;
}   //挖坑法归位
void quick_sort(int* a,int start,int end){
    if(start<end){
        int pivot=part_sort(a,start,end);
        quick_sort(a,start,pivot-1);
        quick_sort(a,pivot+1,end);
    }   //递归
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    quick_sort(a,1,n);
    for(int i=1;i<=n;i++){
        cout<<a[i]<<endl;
    }
    return 0;
}