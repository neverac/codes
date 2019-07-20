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

char s[200010];
int main(){
	int n=read();
	scanf("%s",s+1);
	int pre  = 1;
	char prec = s[1];
	for (int i=2; i<=n; i++)
		if (s[i]==prec) pre++;
		else break;
	int las = 1;
	char lasc = s[n];
	for (int i=n-1; i>=1; i--)
		if (s[i]==lasc) las++;
		else break;
	LL ans=0;
	ans = (pre+las+1) % P;
	// printf("%d %d %d\n",ans,pre,las);
	if (lasc==prec){
		int l = pre+1;
		int r = n-las;
		ans = (ans + 1LL*(pre)*(las)%P)%P;
	}
	printf("%lld\n",ans);
	return 0;
}
