#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
#define ll long long 
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48,ch=getchar();}
	return x*f;
}
const int maxn = 1010;
const int maxm = 1010;

struct edge{
	int to,next,dis;
}e[maxm*2];
int tot,head[maxn];
void add(int u,int v,int w){
	e[++tot].to=v;
	e[tot].dis=w;
	e[tot].next=head[u];
	head[u]=tot;
}
struct Node{
	int num,dis;
	Node(){}
	Node(int a,int b){num=a,dis=b;}
	bool operator < (const Node &x)const{
		return dis>x.dis;
	}
};
int dis[maxn],dis2[maxn],n,m;
priority_queue<Node>q;
int dijkstra(int s,int *d){
	for(int i=1;i<=n;i++) d[i]=0x3f3f3f3f;
	q.push(Node(s,0));d[s]=0;
	while(!q.empty()){
		Node x=q.top();q.pop();
		if(d[x.num]!=x.dis) continue;
		for(int i=head[x.num];i;i=e[i].next){
			int to=e[i].to;
			if(d[to]>d[x.num]+e[i].dis){
				d[to]=d[x.num]+e[i].dis;
				q.push(Node(to,d[to]));
			}
		}
	}
}
bool vis[maxn][maxn];
int main(){
	
	n=read(),m=read();
	int S=read(),T=read();

	for(int i=1;i<=m;i++){
		int a=read(),b=read();
		add(a,b,1);add(b,a,1);
		vis[a][b]=1;
		vis[b][a]=1;
	}
	dijkstra(S,dis);
	dijkstra(T,dis2);
	// for(int i=1;i<=n;i++)
	// 	printf("%d ",dis[i]);puts("");
	// for(int i=1;i<=n;i++)
	// 	printf("%d ",dis2[i]);puts("");
	
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j||vis[i][j]) continue;
			if(dis[i]+1+dis2[j]<dis[T]) continue;
			if(dis[j]+1+dis2[i]<dis[T]) continue;
			ans++;
		}
	}
	printf("%d\n",ans/2);
	return 0;
}
