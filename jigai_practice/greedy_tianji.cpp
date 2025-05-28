#include<bits/stdc++.h>
using namespace std;
int qi[1005],tian[1005];
int main(){
    ios::sync_with_stdio(false);
    int n;
    while(cin>>n){
        if(n==0){
            break;
        }
        else{
            int good{0},bad{n-1},qibad{n-1},qigood{0},ans{0};
            for(int i=0;i<n;i++){
                cin>>tian[i];
            }
            for(int i=0;i<n;i++){
                cin>>qi[i];
            }
            sort(tian,tian+n,greater<int>());
            sort(qi,qi+n,greater<int>());
            while(good<=bad){
                if(tian[good]>qi[qigood]){
                    good++;
                    qigood++;
                    ans=ans+200;
                }
                else if(tian[good]<qi[qigood]){
                    bad--;
                    qigood++;
                    ans=ans-200;
                    
                }
                else{
                    if(tian[bad]>qi[qibad]){
                        bad--;
                        qibad--;
                        ans=ans+200;
                    }
                    else{
                        if(tian[bad]<qi[qigood]){
                            ans=ans-200;
                            bad--;
                            qigood++;
                        }
                        else{
                            bad--;
                            qigood++;
                        }
                    }
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}