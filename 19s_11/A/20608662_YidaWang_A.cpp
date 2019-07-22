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

int N,M,S,T;
int d[100010];
int main(){
	N=read();
	LL sum=0,ans=0;
	for (int i=1; i<=N; i++) d[i]=read(),sum+=d[i];
	sort(d+1,d+N+1);
	for (int i=1; i<=N; i++){
		ans += 1LL*(d[i]+d[i-1])*sum;
		sum-=d[i];
	}
	printf("%lld\n",ans);
	return 0;
}