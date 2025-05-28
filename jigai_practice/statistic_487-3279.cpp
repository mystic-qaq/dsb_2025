#include <bits/stdc++.h>
using namespace std;
struct number{
	string num;
	int time;
};
bool cmp1(string a1,string a2){
	return a1<a2;
}
string y[100001]{};
number x[100001]{};
int main(){
	int n;
	cin>>n;
	getchar();
	for(int i=1;i<=n;i++){
		int t{0};
		string a{},b{};
		getline(cin,a);
		for(int j=0;j<=a.length()-1;j++){
			if(a[j]!='-'){
				b=b+a[j];
				t++;
			}
			if(t==3 and b[3]!='-'){
				b=b+"-";
			}
		}
		for(int j=0;j<=7;j++){
			if(b[j]>='A' and b[j]<='R'){
				b[j]=(b[j]-'A')/3+'2';
			}
			if(b[j]>='S' and b[j]<='Y'){
				b[j]=(b[j]-'Q')/3+'7';
			}
		}
		y[i]=b;
		cout<<y[i]<<endl;
	}
	sort(y+1,y+n+1,cmp1);//注意顺序，对时间复杂度的优化；
	x[0].num=y[1];
	x[0].time=1;
	int m{0},flag{0};
	for(int i=2;i<=n;i++){
		if(y[i]==x[m].num){
			x[m].time++;
		}
		else{
			m++;
			x[m].num=y[i];
			x[m].time=1;
		}
	}
	for(int i=0;i<=m;i++){
		if(x[i].time>=2){
			cout<<x[i].num<<" "<<x[i].time<<endl;
			flag=1;
		}
	}
	if(flag==0){
		cout<<"No duplicates."<<endl;
	}
	return 0;
}