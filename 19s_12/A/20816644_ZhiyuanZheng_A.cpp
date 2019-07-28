#include <bits/stdc++.h>
using namespace std;
int p,q;
bool a[10];
int main(){
	cin>>p>>q;
	p%=q;
	int cnt=0;
	while (cnt<=1000){
		p*=10;
		a[p/q]=1;
		p%=q;
		cnt++;
	}
	for (int i=0;i<=9;i++) if (a[i]==1) cout<<i;
	cout<<endl;
	return 0;
}

