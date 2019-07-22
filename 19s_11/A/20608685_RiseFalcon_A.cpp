#include <bits/stdc++.h>
typedef long long TYPE;
const TYPE mod=1E9+7;
const int MAXN=1E5+10;
const int INF=~0U>>1;
int input() {
	int x;scanf("%d",&x);
	return x;
}
TYPE d[MAXN];
int main() {
	int N=input();
	TYPE sum=0,ans=0;
	for(int i=1;i<=N;++i) {
		d[i]=input();
		sum+=d[i];
	}
	std::sort(d+1,d+N+1);
	std::reverse(d+1,d+N+1);
	for(int i=1;i<=N;++i) {
		ans+=sum*d[i];
		sum-=d[i];
		ans+=sum*d[i];
	}printf("%lld\n",ans);
	return 0;
}
