#include <bits/stdc++.h>
using namespace std;
int x[180];
int main(){
	int T;
//	for (int i=0;i<180;i++) x[i]=i+1;
	cin>>T;
//	T=179;
	while (T--){
		int ang;
		cin>>ang;
//		cout<<ang<<endl;
		if (180%ang==0&&ang<90) cout<<180/ang<<endl;
		else {
			bool flag=true;
			for (int i=3;i<=360;i++){
				double x=(180.0*(i-2))/i;
				double y=180.0/i;
				if (ang<=x&&ang>=y) {
					int m=ang/y;
					if (abs(ang-x)<=1e-6||abs(y*m-ang)<=1e-6){
						cout<<i<<endl;
						flag=false;
						break;
					}
				}
			}
			if (flag) cout<<-1<<endl;
		}
	}
	return 0;
}

