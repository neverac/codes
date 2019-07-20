#include <bits/stdc++.h>
typedef long long TYPE;
const int MAXN=1E5+10;
const int INF=~0U>>1;
const TYPE mod=1E9+7;
int input() {
	int x;scanf("%d",&x);
	return x;
}
int Z=0,F=0,N=0;
TYPE a[MAXN],b[MAXN];
int doingZ() {
	TYPE x=a[1];
	for(int i=3;i<=Z;++i) {
		x-=a[i];
	}
	if(Z>=2) {
		x=a[2]-x;
	}
	printf("%lld\n",x);
	x=a[1];
	for(int i=3;i<=Z;++i) {
		printf("%lld %lld\n",x,a[i]);
		x-=a[i];
	}
	if(Z>=2) {
		printf("%lld %lld\n",a[2],x);
		x=a[2]-x;
	}
}
int doingZF() {
	TYPE x=b[F];
	for(int i=1;i<Z;++i) {
		x-=a[i];
	}x=a[Z]-x;
	for(int i=1;i<F;++i) {
		x-=b[i];
	}
	printf("%lld\n",x);
	x=b[F];
	for(int i=1;i<Z;++i) {
		printf("%lld %lld\n",x,a[i]);
		x-=a[i];
	}
	printf("%lld %lld\n",a[Z],x);
	x=a[Z]-x;
	for(int i=1;i<F;++i) {
		printf("%lld %lld\n",x,b[i]);
		x-=b[i];
	}
}
int doingF() {
	TYPE x=b[F];
	for(int i=1;i<F;++i) {
		x-=b[i];
	}
	printf("%lld\n",x);
	x=b[F];
	for(int i=1;i<F;++i) {
		printf("%lld %lld\n",x,b[i]);
		x-=b[i];
	}
} 
int main() {
	N=input();
	for(int i=1;i<=N;++i) {
		int x=input();
		if(x>0) {
			a[++Z]=x;
		}else {
			b[++F]=x;
		}
	}
	std::sort(a+1,a+Z+1);
	std::sort(b+1,b+F+1);
	if(Z==0&&F!=0)doingF();
	if(Z!=0&&F!=0)doingZF();
	if(Z!=0&&F==0)doingZ();
	return 0;
}
