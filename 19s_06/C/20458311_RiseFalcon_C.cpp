#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long TYPE;
const int MAXN=4E5+10;
const TYPE mod=1E9+7;
struct pir{
	int x,i;
	pir(int a=0,int b=0) {
		x=a;i=b;
	}
}w[MAXN];
bool operator < (const pir&a,const pir&b) {
	return a.x>b.x;
}
int a[MAXN];
int v[MAXN];
int main() {
	int N,M,K;
	TYPE ans=0;
	scanf("%d%d%d",&N,&M,&K);
	for(int i=1;i<=N;++i) {
		scanf("%d",&a[i]);
		w[i]=pir(a[i],i);
	}
	std::sort(w+1,w+N+1);
	for(int i=1;i<=M*K;++i) {
		ans+=w[i].x;
		v[w[i].i]=1;
	}
//	for(int i=1;i<=N;++i) {
//		printf("%d ",v[i]);
//	}printf("\n");
	int cnt=0;
	printf("%lld\n",ans);
	for(int i=1;i<=N;++i) {
		cnt+=v[i];
		if(cnt>M) {
			printf("%d ",i-1);
			cnt=1;
		}
	}
	return 0;
}