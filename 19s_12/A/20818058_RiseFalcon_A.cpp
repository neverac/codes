#include <bits/stdc++.h>
typedef long long TYPE;
const TYPE mod=998244353;
const int MAXN=1E6+10;
const int INF=~0U>>1;
const TYPE x=13;
int input() {
	int x;scanf("%d",&x);
	return x;
}
int main() {
	TYPE P,Q;
	bool vis[10];
	memset(vis,0,sizeof vis);
	scanf("%lld%lld",&P,&Q);
	P%=Q;
	if(P*10<Q) {
		vis[0]=1;
	}
	while(P<Q)P*=10;
	for(int i=1;i<=1E7;++i) {
		TYPE x=P/Q;P%=Q;
		if(x==0) {
			vis[0]=1;
		}
		while(x!=0) {
			int t=x%10;x/=10;
			vis[t]=1;
		}
		if(P==0)break;
		if(P<Q)P*=10;
		
	}
	for(int i=0;i<10;++i) {
		if(vis[i]) {
			printf("%d",i);
		}
	}
	return 0;
}
