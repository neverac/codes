#include <bits/stdc++.h>
typedef long long TYPE;
const TYPE mod=1E9+7;
const int MAXN=1E6+10;
const TYPE INF=~0ULL>>1;
int input() {
	int x;scanf("%d",&x);
	return x;
}
TYPE h[MAXN][2],f[MAXN][2][2];
int main() {
	int N=input();
	for(int i=1;i<=N*2;++i) {
		int x=input();
		if(h[x][0]==0) {h[x][0]=i;}
		else h[x][1]=i;
	}
	f[0][0][1]=f[0][0][0]=0;
	h[0][0]=h[0][1]=1;
	for(int i=1;i<=N;++i) {
		f[i][0][1]=INF;
		f[i][0][1]=std::min(f[i-1][0][1]+abs(h[i][0]-h[i-1][0])+abs(h[i][1]-h[i-1][1]),f[i][0][1]);
		f[i][0][1]=std::min(f[i-1][1][0]+abs(h[i][0]-h[i-1][1])+abs(h[i][1]-h[i-1][0]),f[i][0][1]);
		f[i][1][0]=INF;
		f[i][1][0]=std::min(f[i-1][1][0]+abs(h[i][0]-h[i-1][0])+abs(h[i][1]-h[i-1][1]),f[i][1][0]);
		f[i][1][0]=std::min(f[i-1][0][1]+abs(h[i][0]-h[i-1][1])+abs(h[i][1]-h[i-1][0]),f[i][1][0]);
	//	printf("%d %d\n",f[i][0][1],f[i][1][0]);
	}
	printf("%lld\n",std::min(f[N][0][1],f[N][1][0]));
	return 0;
}
