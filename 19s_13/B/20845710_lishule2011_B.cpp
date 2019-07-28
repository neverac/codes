#include <iostream>
#include <cstring>
#include <cmath>
#define maxn 200500
using namespace std;
struct Node{
	int l;
	int r;
}a[maxn];
long long f[maxn][3];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(a,0,sizeof(a));
	memset(f,0,sizeof(f));
	int n;
	cin >> n;
	for (int i=1;i<=2*n;i++){
		int x;
		cin >> x;
		if (!a[x].l)a[x].l = i;else a[x].r = i; 
	}

	for(int i=1;i<=n;i++){
		int x00=abs(a[i-1].l-a[i].l);
		int x01=abs(a[i-1].l-a[i].r);
		int x10=abs(a[i-1].r-a[i].l);
		int x11=abs(a[i-1].r-a[i].r);

	
	 	f[i][0]=min(f[i-1][0]+x00+x11,
	 			 	f[i-1][1]+x10+x01);
		f[i][1]=min(f[i-1][0]+x01+x10,
	 			 	f[i-1][1]+x11+x00);
	}
	long long  ans = min(f[n][0],f[n][1]) -2;
	cout << ans; 

}