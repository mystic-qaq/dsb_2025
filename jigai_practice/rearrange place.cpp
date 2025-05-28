#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  string words[1000];
  getline(cin,s);    //注意这种输入方式！当然之前记得getchar();
  int len=s.size();  //注意这个函数！
  bool first=true;
  int count=0,countthenull=0;
  for(int i=0;i<len;i++){
    while(s[i]==' '){
      i++;
      first=true;//这里的first是一个很妙的判断，是否是第一个字母；
      countthenull++;
    }
    if(s[i]<='z' and s[i]>='a' and first){
      first=false;
      count++;
      words[count]=s[i];
    } else if(s[i]<='z' and s[i]>='a' and !first){
      words[count]=words[count]+s[i];
    }
  }
  if(count==1){
    cout<<words[count];
    for(int i=0;i<countthenull;i++){
      cout<<" ";
    }
  }
  else{
    cout<<words[1];
    int gap=countthenull/(count-1);
    for(int i=2;i<=count;i++){
      for(int j=0;j<gap;j++){
        cout<<" ";
      }
      cout<<words[i];
    }
    for(int k=1;k<=countthenull%(count-1);k++){
      cout<<" ";
    }
  }
  return 0;
}