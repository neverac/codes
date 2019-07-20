#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
#define N 1001000
#define M 1001000
using namespace std;
int dis[N],nxt[M],to[M],w[M],head[N];
int n,m,s,t;
queue<int> q;
inline int read(){
	char ch;
	int f=1,res=0;
	while((ch=getchar())<'0'||ch>'9')
		if(ch=='-') f=-1;
	while(ch>='0'&&ch<='9')
	{
		res=(res<<1)+(res<<3)+(ch^48);
		ch=getchar();
	}
	return f*res;
}
int tot=0;
bool vis[N];
void add(int x,int y,int z){
	nxt[++tot]=head[x];
	head[x]=tot;
	w[tot]=z;
	to[tot]=y;
}

void spfa(int u){
	while (!q.empty()) q.pop();
	q.push(u);
	vis[u]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		vis[x]=0;
		for(int i=head[x];i;i=nxt[i]){
			int y=to[i];
			if(dis[x]+w[i]<dis[y]){
				dis[y]=dis[x]+w[i];
				if(!vis[y]) vis[y]=1,q.push(y);
			}
		}
	}
}

bool vis1[N];
queue<int> q1;
int dis1[N];

void spfa1(int u){
	q1.push(u);
	vis1[u]=1;
	while(!q1.empty()){
		int x=q1.front();
		q1.pop();
		vis1[x]=0;
		for(int i=head[x];i;i=nxt[i]){
			int y=to[i];
			if(dis1[x]+w[i]<dis1[y]){
				dis1[y]=dis1[x]+w[i];
				if(!vis1[y]) vis1[y]=1,q1.push(y);
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//memset(G,0,sizeof(G));
	cin >> n;
	m = n-1;
	//n=read();m=read();s=read();t=read();
	int i,j,k;
	for(i=1;i<=m;++i)
	{
		int x,y;
		cin >> x >>y;
		//x=read();y=read();
		add(x,y,1);
		add(y,x,1);
		//G[x][y] =1,G[y][x]=1;
		
	}	
	for(i=1;i<=n;++i)
	{
		// dis1[i]=2147483647;
		// vis1[i]=0;
		dis[i]=0x3f3f3f3f;
		vis[i]=0;
	}
	t=1;
	dis[t]=0;
	spfa(t);
	int x,maxx=-1;
	for (int i=1;i<=n;i++) if (dis[i]>maxx)maxx=dis[i],x=i;
	//cout << x<<"asa";
	for(i=1;i<=n;++i)
	{
		// dis1[i]=2147483647;
		// vis1[i]=0;
		dis[i]=0x3f3f3f3f;
		vis[i]=0;
	}
	dis[x]=0;
	spfa(x);
	// for(i=1;i<=n;++i)
	// 	printf("%d %d\n",dis[i],dis1[i]);
	maxx=-1;
	for (int i=1;i<=n;i++) if (dis[i]>maxx)maxx=dis[i],x=i;	
	maxx++;	
//	cout << maxx;
	cout << (maxx%3 == 2?"Second":"First");
	// int ans=0;
	// for (int i=1;i<=n;i++)
	// 	for (int j=i+1;j<=n;j++) if (!G[i][j]){
	// 		if (dis[i]+dis1[j]+1>=dis[t] && dis1[i]+dis[j]+1>=dis[t] ) ans++;//,cout << i << ' '<<j<<endl;
	// 	}
	// 	cout << ans;
	return 0;
}