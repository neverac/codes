#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long TYPE;
const int MAXN=1E6+10;
int prime[MAXN+10],vis[MAXN+10],cnp;
void pre(const int N=MAXN) {
	for(int i=1;i<=N;++i) {
		if(!vis[i]) {
			prime[++cnp]=i;
		}
		for(int j=1;j<=cnp&&prime[j]*i<=N;++j) {
			vis[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		}
	}
}
int main() {
	TYPE x,y,z;
	TYPE a,b,c;
	scanf("%lld%lld%lld",&x,&y,&z);
	scanf("%lld%lld%lld",&a,&b,&c);
	if(
		(a<x)
	||	(a+b-x<y)
	||	(a+b+c-x-y<z)
	) {
		printf("NO\n");
	}else printf("YES\n");
	return 0;
}