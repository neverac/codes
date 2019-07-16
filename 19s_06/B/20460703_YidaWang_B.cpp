#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <vector>
#include <ctime>
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
int ti=60;
inline int check(int x){
	printf("> %d\n",x);
	fflush(stdout);
	int re; scanf("%d",&re);
	ti--;
	return re;
}
int a[100010];
int visit[1000010];

int gcd(int a,int b){
	if (!b) return a;
	else return gcd(b,a%b);
}

int main(){
	int n=read();

	if (ti>=n){
		for (int i=1; i<=n; i++){
			printf("? %d\n",i);
			fflush(stdout);
			scanf("%d",&a[i]);
		}
		sort(a+1,a+n+1);
		printf("! %d %d\n",a[1],a[2]-a[1]);
		return 0;
	}

	int l=0,r=1000000000,ans=r;
	while (l<=r){
		int mid=(l+r)>>1;
		if (check(mid)) l=mid+1;
		else ans=min(ans,mid),r=mid-1;
	}

	int pos = 1;	
	srand(time(0));
	int cnt=0;
	while (cnt<ti){
		int t = rand()*rand()%n+1;
		if (visit[t]) continue;
		else {
			a[++cnt]=t;
			visit[t]=1;
		}
	}
	for (int i=1; i<=cnt; i++){
			printf("? %d\n",a[i]);
			fflush(stdout);
			scanf("%d",&a[i]);
	}
	
	sort(a+1,a+cnt+1);

	int ansd = a[2]-a[1];
	for (int i=3; i<=cnt; i++){
		if (a[i]-a[i-1]!=0) ansd=gcd(ansd,a[i]-a[i-1]);
	}

	printf("! %d %d\n",ans-(n-1)*ansd,ansd);
	fflush(stdout);

	return 0;
}