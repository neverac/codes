#include<bits/stdc++.h>
using namespace std;
int const maxn=2e3+100,maxn2=1e3+10;
int n,m,s,w,head[maxn2],tot=0,dis[3][maxn2];
bool vis[maxn2],ma[maxn2][maxn2];
struct edge{
	int t,next;
}e[maxn];
inline int get_num(){
	char ch;
	int num=0;
	ch=getchar();
	while(ch<'0'||ch>'9'){ch=getchar();}
	while(ch>='0'&&ch<='9'){num=(num<<3)+(num<<1)+ch-'0';ch=getchar();}
	return num;
}
void build(int x,int y){
	e[++tot].t=y;e[tot].next=head[x];head[x]=tot;
}
void bfs(int x,int y){
	queue<int>q;
	memset(vis,0,sizeof(vis));
	dis[y][x]=0;
	int o,u;
	q.push(x);
	vis[x]=true;
	while(!q.empty()){
		o=q.front();q.pop();
		for(int i=head[o];i;i=e[i].next){
			u=e[i].t;if(!vis[u]){
				dis[y][u]=dis[y][o]+1;
				q.push(u);
				vis[u]=1;
			}
		}
	}
}
int ans=0;
void work(){
	int z=dis[0][w];
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)if(!ma[i][j]){
			if(dis[0][i]+1+dis[1][j]>=z&&dis[1][i]+1+dis[0][j]>=z)ans++;
		}
}
int main(){
	int a,b;
	scanf("%d%d%d%d",&n,&m,&s,&w);
	for(int i=1;i<=m;i++){
		a=get_num(),b=get_num();
		ma[a][b]=1,ma[b][a]=1;
		build(a,b);build(b,a);
	}
	bfs(s,0);bfs(w,1);
	//for(int i=1;i<=n;i++)cout<<dis[i]<<" ";
	//	cout<<endl;
	work();
	cout<<ans<<endl;
	return 0;
}