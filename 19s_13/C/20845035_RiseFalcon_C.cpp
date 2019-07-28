#include <bits/stdc++.h>
typedef long long TYPE;
const TYPE mod=1E9+7;
const int MAXN=100+10;
const int INF=~0U>>1;
int input() {
	int x;scanf("%d",&x);
	return x;
}
const int ud[4]={0,1,0,-1};
const int lr[4]={1,0,-1,0};
int mp[MAXN][MAXN];
struct pair {
	int x,y;
	pair(int a=0,int b=0) {
		x=a;y=b;
	}
};
int main() {
	int N=input();
	int r1=input();
	int c1=input();
	int r2=input();
	int c2=input();
	for(int i=1;i<=N;++i) {
		for(int j=1;j<=N;++j) {
			scanf("%1d",&mp[i][j]);
		}
	}
	std::queue <pair>q;
	mp[r1][c1]=2;
	q.push(pair(r1,c1));
	while(!q.empty()) {
		pair o=q.front();q.pop();
		int x=o.x,y=o.y;
		for(int id=0;id<4;++id) {
			int xx=o.x+ud[id];
			int yy=o.y+lr[id];
			if(xx<1||xx>N||yy<1||yy>N||mp[xx][yy]==1)continue;
			if(mp[xx][yy]!=2) {
				mp[xx][yy]=2;
				q.push(pair(xx,yy));
			}
		}
	}
	mp[r2][c2]=3;
	q.push(pair(r2,c2));
	while(!q.empty()) {
		pair o=q.front();q.pop();
		int x=o.x,y=o.y;
		for(int id=0;id<4;++id) {
			int xx=o.x+ud[id];
			int yy=o.y+lr[id];
			if(xx<1||xx>N||yy<1||yy>N||mp[xx][yy]==1)continue;
			if(mp[xx][yy]!=3) {
				mp[xx][yy]=3;
				q.push(pair(xx,yy));
			}
		}
	}
	if(mp[r1][c1]==mp[r2][c2]) {
		printf("%d\n",0);
	}else {
		int ans=INF;
		auto f=[](int x) {return x*x;};
		for(int x1=1;x1<=N;++x1) {
		for(int y1=1;y1<=N;++y1) {
			for(int x2=1;x2<=N;++x2) {
			for(int y2=1;y2<=N;++y2) {
				if(mp[x1][y1]==2 && mp[x2][y2]==3) {
					ans=std::min(ans,f(x1-x2)+f(y1-y2));
				}
			} 
			}
		}
		}printf("%d\n",ans);
	}
	return 0;
}
