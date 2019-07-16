#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <vector>

using namespace std;
#define LL long long
#define INF 0x7fffffff
#define P 998244353

inline LL read(){
    LL x=0,f=1; char ch=getchar();
    while (ch<'0' || ch>'9') {if (ch=='-') f=-1; ch=getchar();}
    while (ch>='0' && ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}

LL n,b;

int flag[1000010],prime[1000010],cnt;
inline void pre(){
	flag[1]=1;
	for (int i=2; i<=1000000; i++){
		if (!flag[i]) prime[++cnt]=i;
		for (int j=1; j<=cnt&&i*prime[j]<=1000000; j++){
			flag[i*prime[j]]=1;
			if (i%prime[j]==0){
				break;
			}
		}
	}
}
int c[1000010];
LL ans=(1LL<<62);
int main(){
	n=read(),b=read();
	pre();
	for (int i=1; i<=cnt; i++){
		while (b%prime[i]==0){
			c[i]++;
			b/=prime[i];
		}
		if (b==1) break;
	}
	// for (int i=1; i<=10; i++) printf("%d ",prime[i]); puts("");
	if (b!=1){
		LL fac=b,t = n,num=0;
		for (int j=1; fac<=n; j++){
			if (fac>t) break;
			if (fac>(1LL<<60)) break;
			num+=t/fac;
			if (fac>=t) break;
			if (t/fac<b) break;
			fac*=b;
		}
		ans=min(ans,num/1);
	}

	for (int i=1; i<=cnt; i++){
		if (!c[i]) continue;
		LL fac=prime[i],t = n,num=0;
		for (int j=1; fac<=n; j++){
			if (fac>t) break;
			if (fac>(1LL<<60)) break;
			num+=t/fac;
			if (fac>=t) break;
			if (t/fac<prime[i]) break;
			fac*=prime[i];
		}
		ans=min(ans,num/c[i]);
	}
	printf("%lld\n",ans);
	return 0;
}