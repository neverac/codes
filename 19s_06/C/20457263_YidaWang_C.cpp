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

struct Node{
	int x,i;
}a[300010];
inline bool cmp1(Node A,Node B){
	return A.x>B.x;
}
inline bool cmp2(Node A,Node B){
	return A.i<B.i;
}
int main(){
	int n=read(),m=read(),k=read();
	for (int i=1; i<=n; i++) a[i].x=read(),a[i].i=i;
	sort(a+1,a+n+1,cmp1);
	
	LL ans=0;
	for (int i=1; i<=m*k; i++) ans+=a[i].x;
	printf("%lld\n",ans);

	sort(a+1,a+m*k+1,cmp2);
	for (int i=1; i<k; i++) printf("%d ",a[i*m].i);
	puts("");

	return 0;
}