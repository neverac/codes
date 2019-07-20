#include <bits/stdc++.h>
typedef long long TYPE;
const TYPE mod=1E9+7;
const int MAXN=1E3+10;
const int INF=~0U>>1;
const int ud[4]={0,1,0,-1};
const int lr[4]={1,0,-1,0};
int input() {
	int x;scanf("%d",&x);
	return x;
}
int vis[MAXN][MAXN];
int dis[MAXN][MAXN];
char mp[MAXN][MAXN];
struct pair{
	int x,y;
	pair(int a=0,int b=0) {
		x=a;y=b;
	}
};
int main() {
	int N=input();
	int M=input();
	for(int i=1;i<=N;++i) {
		scanf("%s",mp[i]+1);
	}
	memset(dis,63,sizeof dis);
	std::queue<pair>q;
	for(int i=1;i<=N;++i) {
		for(int j=1;j<=M;++j) {
			if(mp[i][j]=='#') {
				q.push(pair(i,j));
				vis[i][j]=1;
				dis[i][j]=0;
			}
		}
	}
	while(!q.empty()) {
		pair o=q.front();q.pop();
		int x=o.x,y=o.y;vis[x][y]=0;
		for(int id=0;id<4;++id) {
			int xx=x+ud[id];
			int yy=y+lr[id];
			if(xx<1||xx>N||yy<1||yy>M)continue;
			if(dis[xx][yy]>dis[x][y]+1) {
				dis[xx][yy]=dis[x][y]+1;
				if(!vis[xx][yy]) {
					vis[xx][yy]=1;
					q.push(pair(xx,yy));
				}
			}
		}
	}
	int ans=0;
	for(int i=1;i<=N;++i) {
		for(int j=1;j<=M;++j) {
			ans=std::max(ans,dis[i][j]);
		}
	}printf("%d\n",ans);
	return 0;
} 