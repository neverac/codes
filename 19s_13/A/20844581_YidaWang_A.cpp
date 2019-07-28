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
int N,a[100010];
int main(){
	N=read();
	for (int i=1; i<=N; i++) a[i]=read();
	int t = ceil(1.0*N/2);
	int mx = 0;
	for (int i=1; i<=N; i++) mx=max(mx,a[i]);
	int d;
	int cnt1=0,cnt2=0;
	for (int i=1; i<=N; i++) if (a[i]>0){
		cnt1++;
	} else if (a[i]<0) cnt2++;
	if (cnt1>=t) printf("1\n");
	else if (cnt2>=t) printf("-1\n");
	else printf("0\n");
	return 0;
}

/*
5
10 0 -7 2 6
7
0 0 1 -1 0 0 2
*/
	