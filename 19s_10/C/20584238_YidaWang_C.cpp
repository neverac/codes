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

LL read(){
    LL x=0,f=1; char ch=getchar();
    while (ch<'0' || ch>'9') {if (ch=='-') f=-1; ch=getchar();}
    while (ch>='0' && ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}

int N,M,S,T;
#define MAXN 200100
struct EdgeNode{
    int next,to,dis,from;
}edge[MAXN<<1];
int head[MAXN],cnt;

void AddEdge(int u,int v,int w) {cnt++; edge[cnt].next=head[u]; head[u]=cnt; edge[cnt].to=v; edge[cnt].from=u; edge[cnt].dis=w;}
void InsertEdge(int u,int v,int w) {AddEdge(u,v,w); AddEdge(v,u,w);}

int deep[MAXN];
void dfs(int now,int last){
	for (int i=head[now]; i; i=edge[i].next)
		if (edge[i].to!=last){
			deep[edge[i].to]=deep[now]+1;
			dfs(edge[i].to,now);
		}
}

int f[MAXN];
int main(){
	N=read();
	for (int i=1; i<=N-1; i++){
		int u=read(),v=read();
		InsertEdge(u,v,1);
	}
	dfs(1,0);
	int mx = 0,mxk;
	for(int i=1; i<=N; i++){
		if (deep[i]>mx) mx=deep[i],mxk=i;
	}
	for (int i=1; i<=N; i++) deep[i]=0;
	dfs(mxk,0);
	for (int i=1; i<=N; i++){
		if (deep[i]>mx) mx = deep[i];
	}
	// printf("%d\n",mx);
	int len = mx+1;
	f[1]=1; f[2]=0;
	for (int i=3; i<=len; i++){
		if (f[i-2] && f[i-1]) f[i]=0;
		else f[i]=1;
	}
	if (f[len]) puts("First");
	else puts("Second");
	return 0;
}
