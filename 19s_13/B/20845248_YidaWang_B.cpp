#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

#define LL long long
#define ULL unsigned long long
#define INF 0x7fffffff

LL read(){
	LL x=0,f=1; char ch=getchar();
	while (ch<'0' || ch>'9') {if (ch=='-') f=-1; ch=getchar();}
	while (ch>='0' && ch<='9') {x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}

#define Pa pair<int,int>
#define MP make_pair

#define MAXN 200010

int N,a[200010],id[100010][2],loc[100010][2],idn;
LL f[100010];

int main(){
	N=read();
	for (int i=1; i<=2*N; i++) a[i]=read();
	for (int i=1; i<=2*N; i++) {
		if (loc[a[i]][0]) loc[a[i]][1]=i-1;
		else loc[a[i]][0]=i-1;
	}
	f[1]=loc[1][0]+loc[1][1];
	
	for (int i=2; i<=N; i++){
		f[i]=(1LL<<60);
		int l1=loc[i][0],l2=loc[i][1];
		f[i]=min(f[i],f[i-1]+abs(l1-loc[i-1][0])+abs(l2-loc[i-1][1]));
		f[i]=min(f[i],f[i-1]+abs(l1-loc[i-1][1])+abs(l2-loc[i-1][0]));
	}
	printf("%lld\n",f[N]);

	return 0;
}

/*
3
1 1 2 2 3 3
2
2 1 1 2
4
4 1 3 2 2 3 1 4
*/
	