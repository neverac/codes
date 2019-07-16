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
	TYPE N,b,ans=~0ULL>>1;
	scanf("%lld%lld",&N,&b);
	for(TYPE i=2;i*i<=b;++i) {
		if(b%i==0) {
			TYPE cnt=0;
			while(b%i==0) {
				b/=i;
				++cnt;
			}
			TYPE x=N,tot=0;
			while(x) {
				tot+=(x/=i);
			}
			ans=std::min(ans,tot/cnt);
		}
	} if(b!=1){
		TYPE i=b,cnt=1;
		TYPE x=N,tot=0;
		while(x) {
			tot+=(x/=i);
		}
		ans=std::min(ans,tot/cnt);
	}
	printf("%lld\n",ans);
	return 0;
}