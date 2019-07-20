#include <iostream>
#include <cstring>
const int maxn=5*1e5+100;
using namespace std;
int a[10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,x;
	cin >> n;
	memset(a,0,sizeof(a));
	int ans=0;
	for (int i=1;i<=n;i++) {
		cin >> x;
		int k;
		if (x == 4) k=1;
		if (x == 8) k=2;
		if (x == 15) k=3;
		if (x == 16) k=4;
		if (x == 23) k=5;
		if (x == 42) k=6;
		x = k;
		if (x == 1)a[1]++;
		else if (a[x-1]) a[x-1]--,a[x]++;
		else ans++;
	}
	for (int i=1;i<=5;i++) ans+=a[i]*i;

	cout << ans;

}