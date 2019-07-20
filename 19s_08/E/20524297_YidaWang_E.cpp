#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <cstdlib>

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
int a[1000010];
int main(){

	int t =read();
	while (t--){
		int n=read();

		for (int i=1; i<=n; i++) a[i]=read();
			int cnt0=0,cnt1=0,cnt2=0;
		for (int i=1; i<=n; i++) if (a[i]%3==0) cnt0++;
			else if (a[i]%3==1) cnt1++;
		else if(a[i]%3==2) cnt2++;
		if (cnt2<cnt1) swap(cnt2,cnt1);
		int t = cnt2 -cnt1;
		int ans=cnt0+cnt1+t/3;
		printf("%d\n",ans);
	}


	// int  K=read(),A=read(),B=read();
	// if (B<=A){
	// 	printf("%d\n",K+1);
	// 	return 0;
	// }
	// int t = K/(A+1);
	// LL ans = 1LL*t*B;
	// int p = K%(A+1);
	// if (p==A) ans+=B;
	// else ans+=p;
	// // LL t = (1LL*A*K-1)/(A+1);
	// // LL ans= (1LL+t)-(1LL+t)/A*A + (1LL+t)/A*B;
	// printf("%lld\n",ans);
	return 0;
}