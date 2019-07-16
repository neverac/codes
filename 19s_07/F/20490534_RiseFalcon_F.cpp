#include <bits/stdc++.h>
typedef long long TYPE;
const TYPE mod=1E9+7;
const int MAXN=1E2+10;
const int MAXL=70;
const int INF=~0U>>1;
const int lr[4]={0,1,0,-1};
const int ud[4]={1,0,-1,0};
int input() {
	int x;scanf("%d",&x);
	return x;
}
struct node {
	int x,y,key;
	node(int a=0,int b=0,int c=0) {
		x=a;y=b;key=c;
	}
};
int inq[MAXN][MAXN][MAXL];
int dis[MAXN][MAXN][MAXL];
int key[MAXN][MAXN];
char mp[MAXN][MAXN];
bool get(int keys,char i) {
	return (keys>>(i-'A'))&1;
}
int main() {
	int N=input();
	int M=input();
	int K=input();
	int x1=input()+1;
	int y1=input()+1;
	int x2=input()+1;
	int y2=input()+1;
	for(int i=1;i<=N;++i) {
		scanf("%s",mp[i]+1);
	}
	for(int i=0;i<K;++i) {
		int x=input()+1;
		int y=input()+1;
		key[x][y]|=(1<<i);
	} 
	memset(dis,63,sizeof dis);
	dis[x1][y1][key[x1][y1]]=0;
	std::queue<node>q;
	q.push(node(x1,y1,key[x1][y1]));
	inq[x1][y1][key[x1][y1]]=1; 
	while(!q.empty()) {
		node o=q.front();q.pop();
		int x=o.x,y=o.y,k=o.key;inq[x][y][k]=0;
	//	printf("[%d,%d,%d]:=%d\n",x,y,k,dis[x][y][k]);
		for(int id=0;id<4;++id) {
			int xx=x+ud[id];
			int yy=y+lr[id];
			if(xx<1 ||xx>N || yy<1 || yy>M)continue;
			char c=mp[xx][yy];
			int kk=k|key[xx][yy];
			if(c=='#' || ('A'<=c&&c<='Z' && !get(k,c)))continue;
			if(dis[xx][yy][kk] > dis[x][y][k] + 1) {
				dis[xx][yy][kk]=dis[x][y][k]+1;
				if(!inq[xx][yy][kk]) {
					q.push(node(xx,yy,kk));
					inq[xx][yy][kk]=1;
				}
			} 
		}
	}
	int ans=INF;
	for(int i=0;i<64;++i) {
		ans=std::min(ans,dis[x2][y2][i]);
	}if(ans>=dis[0][0][0])printf("-1");
	else printf("%d\n",ans);
	return 0;
}
