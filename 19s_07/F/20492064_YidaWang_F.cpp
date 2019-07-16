#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>

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
char mp[300][300],id[300];

int N,M,K,Sx,Sy,Ex,Ey,ans=-1,keyx[100],keyy[100],dis[110][110][35];

struct Node{
	int x,y,k,d;
	Node(){}
	Node(int X,int Y,int K,int D){
		x=X,y=Y,k=K,d=D;
	}
};

int dx[4]={0,0,-1,1},dy[4]={-1,1,0,0};

#define nx now.x
#define ny now.y
#define nk now.k
#define nd now.d

inline bool check(int x,int y,int k){
	if (x<0 || x>N-1) return 0;
	if (y<0 || y>M-1) return 0;
	if (mp[x][y]=='#') return 0;
	for (int i=0; i<K; i++){
		if (mp[x][y]==id[i] && !((1<<i)&k)) return 0;
		// printf("fuck %d %d %d %c %c\n",x,y,k,id[i],mp[x][y]);
	}
	return 1;
}

void BFS(){
	queue<Node>q;
	int sk=0;
	for (int i=0; i<K; i++){
		if (Sx==keyx[i] && Sy==keyy[i]) sk|=1<<i;
	}
	
	for (int i=0; i<N; i++) for (int j=0; j<M; j++) for (int k=0; k<=32; k++) dis[i][j][k]=INF;
	q.push(Node(Sx,Sy,sk,0));
	dis[Sx][Sy][sk]=0;
	while (!q.empty()){
		Node now = q.front();
		q.pop();
		// printf("debug %d %d %d %d\n",nx,ny,nk,nd);
		if (dis[nx][ny][nk]<nd) continue;

		if (nx==Ex && ny==Ey) {
			ans = dis[nx][ny][nk];
			return;
		}

		for (int i=0; i<4; i++){
			int tx = nx+dx[i], ty = ny+dy[i], tk = nk,td = nd+1;
			if (!check(tx,ty,tk) || dis[tx][ty][tk]<=td) continue;
			for (int j=0; j<K; j++){
				if (keyx[j]==tx && keyy[j]==ty) tk|=(1<<j);
			}	

			dis[tx][ty][tk]=td;
			q.push(Node(tx,ty,tk,td));

		}

	}
}

int main(){
	
	N=read(),M=read(),K=read(),Sx=read(),Sy=read(),Ex=read(),Ey=read();
	for (int i=0; i<N; i++){
		scanf("%s",mp[i]);
	}
	for (int i=0; i<K; i++){
		keyx[i]=read(),keyy[i]=read();
		id[i]='A'+i;
	}
	BFS();

	bool flag=0;
	for (int i=0; i<=32; i++){
		if (dis[Ex][Ey][i]<INF) flag = 1;
	}
	if (flag)
		printf("%d\n",ans);
	else puts("-1");

	return 0;
}