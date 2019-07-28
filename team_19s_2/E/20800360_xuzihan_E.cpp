/*	TJU [2019暑期训练] 组队赛2 E Ambush
	1st Edition:2019.7.26 Friday
	Algorithm:Dinic
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cassert>
using namespace std;

#define is_lower(c) (c>='a' && c<='z')
#define is_upper(c) (c>='A' && c<='Z')
#define is_alpha(c) (is_lower(c) || is_upper(c))
#define is_digit(c) (c>='0' && c<='9')
#define stop system("PAUSE")
#define ForG(i,a,b,c) for(rg int (i)=c.head[a],(b)=c.E[i].v;(i);(i)=c.E[i].nxt,(b)=c.E[i].v)
#define ForR(a,b,c) for(rg int (a)=b;(a)>=(c);--(a))
#define For(a,b,c) for(rg int (a)=(b);(a)<=(c);++a)
#define qmin(a,b) ((a)<(b)?(a):(b))
#define qmax(a,b) ((a)>(b)?(a):(b))
#define qabs(a) ((a)>=0?(a):-(a))
#define shl(x,y) ((x)<<(y))
#define shr(x,y) ((x)>>(y))
#define pc __builtin_popcount
#define mp make_pair
#define pb push_back
#define rg register
#ifdef ONLINE_JUDGE
#define hash rename_hash
#define next rename_next
#define prev rename_prev
#endif
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ull,ull> pull;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef double db;
const ll inf=1000000007LL;
const db EPS=1e-10;
const ll inf_ll=(ll)1e18;
const ll maxn=1005LL;
const ll maxm=40005LL;
const ll mod=1000003LL;

struct Graph{
	struct edge{
		int u,v,f,rev,nxt;
		edge(int u=0,int v=0,int f=0,int nxt=0,int rev=0):u(u),v(v),f(f),nxt(nxt),rev(rev){}
	}E[maxm];
	int head[maxn],cnt;
	void init(){
		cnt=0;
		memset(head,0,sizeof(head));
	}
	inline void link(int u,int v,int f){
		int tmp=cnt;
		E[++cnt]=edge(u,v,f,head[u],tmp+2);head[u]=cnt;
		E[++cnt]=edge(v,u,0,head[v],tmp+1);head[v]=cnt;
	}
}G;

int Case;
int n,m,S,T,k;
int d[maxn],cur[maxn];

void bfs(){
	memset(d,-1,sizeof(d));
	queue<int> que;
	que.push(S);
	d[S]=0;
	while(!que.empty()){
		int u=que.front();que.pop();
		ForG(i,u,v,G) if(G.E[i].f && d[v]<0){
			d[v]=d[u]+1;
			que.push(v);
		}
	}
}

int dfs(int u,int max_f){
	if(u==T) return max_f;
	for(int i=cur[u],v=G.E[i].v;i;i=G.E[i].nxt,v=G.E[i].v){
		if(!G.E[i].f || d[u]+1!=d[v]) continue;
		int tmp=dfs(v,min(max_f,G.E[i].f));
		if(tmp){
			G.E[i].f-=tmp;
			G.E[G.E[i].rev].f+=tmp;
			return tmp;
		}
	}
	return 0;
}

int dinic(){
	int ans=0;
	while(true){
		For(i,1,n) cur[i]=G.head[i];
		bfs();
		if(d[T]<0) break;
		while(true){
			int tmp=dfs(S,inf);
			if(!tmp) break;
			ans+=tmp;
		}
	}
	return ans;
}

int main(){
	scanf("%d",&Case);
	while(Case--){
		G.init();
		scanf("%d%d%d%d%d",&n,&m,&S,&T,&k);
		k=(k-1)/3+1;
		For(i,1,m){
			int u,v;
			scanf("%d%d",&u,&v);
			G.link(u,v,1);
			G.link(v,u,1);
		}
		printf("%d\n",dinic()*k);
	}
	return 0;
}