#include <bits/stdc++.h>
using namespace std;
int n;

int main(){
	cin>>n;
	int a1=0,a2=0;
	for (int i=1;i<=n;i++){
		double x;
		cin>>x;
		if (x>0) a1++;
		if (x<0) a2++;
	}
	int k=(n+1)/2;
	if (a1>=k) cout<<1<<endl;
	else if (a2>=k) cout<<-1<<endl;
	else cout<<0<<endl;
	return 0;
}