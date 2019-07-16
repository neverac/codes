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
int n,m,K,sx,sy,tx,ty;
char mp[110][110];
int dis[110][110][110],door[110][110];
int dx[]={0,1,-1,0,0};
int dy[]={0,0,0,1,-1};
struct Node{
	int x,y,s,dis;
	Node(int a,int b,int c,int d){
		x=a,y=b,s=c,dis=d;
	}
};
queue<Node>q;
int bfs(){
	memset(dis,0x3f,sizeof dis);
	int sta=0;
	if(door[sx][sy]!=-1) sta=1<<door[sx][sy];
	q.push(Node(sx,sy,sta,0));
	while(!q.empty()){
		Node u=q.front();q.pop();
		//printf("%d %d\n",u.x,u.y);
		if(u.x==tx&&u.y==ty) return u.dis;
		if(dis[u.x][u.y][u.s]<=u.dis) continue;
		dis[u.x][u.y][u.s]=u.dis;
		for(int i=1;i<=4;i++){
			int xx=u.x+dx[i],yy=u.y+dy[i];
			if(xx<0||xx>n||yy<0||yy>m) continue;
			if(mp[xx][yy]=='#') continue;
			if(mp[xx][yy]=='.'){
				if(door[xx][yy]!=-1)
					q.push(Node(xx,yy,u.s|(1<<door[xx][yy]),u.dis+1));
				else
					q.push(Node(xx,yy,u.s,u.dis+1));
			}else{
				int p=mp[xx][yy]-'A';
				if(u.s&(1<<p))
					q.push(Node(xx,yy,u.s,u.dis+1));
			}
		}
	}
	return -1;
}
int main(){
	
	n=read(),m=read();
	K=read();
	sx=read()+1,sy=read()+1;
	tx=read()+1,ty=read()+1;
	for(int i=1;i<=n;i++)
		scanf("%s",mp[i]+1);
	memset(door,-1,sizeof door);
	for(int i=0;i<K;i++){
		int x=read()+1,y=read()+1;
		door[x][y]=i;
	}
	printf("%d\n",bfs());
	return 0;
}
  