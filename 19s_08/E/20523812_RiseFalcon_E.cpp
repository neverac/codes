#include <bits/stdc++.h>
typedef long long TYPE;
const TYPE mod=1E9+7;
const int MAXN=1E5+10;
const int INF=~0U>>1;
int input() {
	int x;scanf("%d",&x);
	return x;
}
int doing() {
	int N=input();
	int tong[3]={0,0,0};
	for(int i=1;i<=N;++i) {
		int x=input();
		tong[x%3]++;
	}
	int x=std::min(tong[1],tong[2]);
	tong[0]+=x;
	tong[1]-=x;
	tong[2]-=x;
	tong[0]+=(tong[1]+tong[2])/3;
	printf("%d\n",tong[0]);
	return 0;
}
int main() {
	int T=input();
	while(T-->0)doing();
	return 0;
}
