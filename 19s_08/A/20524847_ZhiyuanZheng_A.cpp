#include <bits/stdc++.h>
using namespace std;
const int maxn=5*1e5+100;
int n;
int a[maxn];
int main(){
	cin>>n;
	int cnt=0;int ans=0;
	for (int i=1;i<=n;i++) {
		int x;
		cin>>x;
//		if (x==4||x==8||x==15||x==16||x==23||x==42) a[++cnt]=x;
		if (x==4) cnt=1;
		if (x==8) cnt=2;
		if (x==15) cnt=3;
		if (x==16) cnt=4;
		if (x==23) cnt=5;
		if (x==42) cnt=6;
		if (cnt!=1&&a[cnt-1]) {
			a[cnt-1]--,a[cnt]++;
			continue;
		}
		if (cnt==1) {
			a[1]++;
			continue;
		}
		ans++;
	}
	for (int i=1;i<=5;i++) ans+=a[i]*i;
	cout<<ans<<endl;
	return 0;
}
