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
#define MAXN 100010
int n,m;
struct qnode{
	int l,r,q;
}q[100010];
int f[31][100010],ans[100010];

struct SegmentTreeNode{
	int l,r,p;
}tree[MAXN<<2];
inline void build(int now,int l,int r){
	tree[now].l=l;
	tree[now].r=r;
	if (l==r){
		tree[now].p=ans[l];
		return;
	}
	int mid=(l+r)>>1;
	build(now<<1,l,mid);
	build(now<<1|1,mid+1,r);
	tree[now].p=tree[now<<1].p&tree[now<<1|1].p;
}
inline int Query(int now,int L,int R){
	int l=tree[now].l,r=tree[now].r;;
	if (L==l && R==r){
		return tree[now].p;
	}
	int mid=(l+r)>>1;
	if (R<=mid) return Query(now<<1,L,R);
	else if (L>mid) return Query(now<<1|1,L,R);
	else return Query(now<<1,L,mid)&Query(now<<1|1,mid+1,R);
}

int main(){
	n=read(),m=read();

	for (int i=1; i<=m; i++){
		q[i].l=read(),q[i].r=read(),q[i].q=read();
		int t=q[i].q;
		for (int j=30; j>=0; j--){
			if ((1<<j)&q[i].q) f[j][q[i].l]++,f[j][q[i].r+1]--;
		}
	// 	Modify(1,q[i].l,q[i].r,t);
	}
	for (int j=30; j>=0; j--){
		for (int i=1; i<=n; i++) f[j][i]+=f[j][i-1];
	}
	for (int i=1; i<=n; i++){
		for (int j=30; j>=0; j--){
			if (f[j][i]) ans[i]+=(1<<j);
		}
		// printf("%d ",ans[i]);
	}

	// puts("");
	build(1,1,n);

	bool flag=1;
	for (int i=1; i<=m; i++){
		int l=q[i].l,r=q[i].r,qq=q[i].q;
		if (Query(1,l,r)!=qq){
			// printf("fuck %d\n",Query(1,l,r));
			flag=0;
			break;
		}
	}
	if (!flag){
		puts("NO");
	} else {
		puts("YES");
		for (int i=1; i<=n; i++) printf("%d ",ans[i]);
		puts("");
	}
	return 0;
}