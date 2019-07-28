#include <bits/stdc++.h>
using namespace std;
int n,d;
int a[1100];
int main(){
	cin>>n;
	while (n!=0){
		cin>>d;
		bool flag=false,ok=false;
		memset(a,0,sizeof a);
		for (int i=1;i<=n;i++)cin>>a[i];
		for (int i=1;i<=n-1;i++){
			if (a[i]+d>=a[i+1]) continue;
			else {
				if (flag) {
					cout<<"N"<<endl;
					ok=true;
					break;
				} 
				if (i==n-1) continue;
				if (a[i+2]-a[i]>=2*d) {
					cout<<"N"<<endl;
					ok=true;
					break;
				} else a[i+1]=a[i]+d,flag=true;
			}
		}
		if (!ok) cout<<"Y"<<endl;
		cin>>n;
	}
	return 0;
}