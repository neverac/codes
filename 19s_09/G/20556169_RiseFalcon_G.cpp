#include <bits/stdc++.h>
typedef long long TYPE;
const TYPE mod=1E9+7;
const int MAXN=1E6+10;
const int INF=~0U>>1;
int input() {
	int x;scanf("%d",&x);
	return x;
}
TYPE f[MAXN];
TYPE sum(TYPE l,TYPE r) {
	return (l+r)*(r-l+1)/2;
}
int main() {
	int N=1E6;
	f[0]=0;
	for(int n=1;n<=N;++n) {
		f[n]=f[n-1]+sum(1,n);
		if(n%2==1) {
			f[n]+=2*sum(1,(n-1)/2);
		}else {
			f[n]+=2*sum(1,n/2)-n/2;
		}
	}
	int T=input();
	for(int i=1;i<=T;++i) {
		printf("%lld\n",f[input()]);
	}
	return 0;
}
