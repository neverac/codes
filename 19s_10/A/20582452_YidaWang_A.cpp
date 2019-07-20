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

struct Node{
	int x,y,d;
	Node (){}
	Node (int X,int Y,int D){
		x=X,y=Y,d=D;
	}
};

int visit[1010][1010],ans,dx[4]={0,0,-1,1},dy[4]={-1,1,0,0};
char mp[1010][1010];
int H,W,Sx,Sy;

inline bool check(int x,int y){
	if (x<1 || x>H) return 0;
	if (y<1 || y>W) return 0;
	if (visit[x][y]) return 0;
	return 1;
}
queue<Node>q;
inline void bfs(){
	
	while (!q.empty()){
		Node now = q.front(); q.pop();
		// printf("debug %d %d %d\n",now.x,now.y,now.d);
		for (int i=0; i<4; i++){
			int tx = now.x+dx[i], ty = now.y+dy[i], td = now.d+1;
			// printf("%d %d %d\n",tx,ty,td);
			if (!check(tx,ty)) continue;
			visit[tx][ty]=1;
			q.push(Node(tx,ty,td));
			
			ans = max(ans,td);
		}
	}
}

int main(){
	H=read(),W=read();
	for (int i=1; i<=H; i++){
		scanf("%s",mp[i]+1);
		for (int j=1; j<=W; j++){
			if (mp[i][j]=='#'){
				q.push(Node(i,j,0));
				visit[i][j]=1;
			}
		}
	}
	bfs();
	printf("%d\n",ans);
	return 0;
}