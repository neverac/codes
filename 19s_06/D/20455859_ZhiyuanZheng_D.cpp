#include <bits/stdc++.h>
using namespace std;
bool ok1,ok2,ok3;
int main(){
	int x,y,z,a,b,c;
	cin>>x>>y>>z;
	cin>>a>>b>>c; 	
	if (a>=x){
		ok1=true;a-=x;
	}
	if (a+b>=y){
		ok2=true;	
	}
	if (a+b+c>=y+z) ok3=true;
	if (ok1&&ok2&&ok3) cout<<"YES\n";else cout<<"NO\n";
	return 0;
}
