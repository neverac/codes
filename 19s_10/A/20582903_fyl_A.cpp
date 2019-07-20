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

struct Node{
	int x,y,z;
	Node(int a,int b,int c){x=a,y=b,z=c;}
};
queue<Node>q;
char mp[1010][1010];
int dis[1010][1010];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int main(){
	int n=read(),m=read();
	for(int i=1;i<=n;i++){
		scanf("%s",mp[i]+1);
		for(int j=1;j<=m;j++){
			if(mp[i][j]=='#')
				q.push(Node(i,j,0));
		}
	}
	memset(dis,0x3f,sizeof dis);
	int ans=0;
	while(!q.empty()){
		Node u=q.front();q.pop();
		if(dis[u.x][u.y]<=u.z) continue;
		dis[u.x][u.y]=u.z;
		ans=max(ans,u.z);
		for(int i=0;i<4;i++){
			int xx=dx[i]+u.x,yy=dy[i]+u.y;
			if(xx<1||xx>n||yy<1||yy>m||mp[xx][yy]=='#')continue;
			q.push(Node(xx,yy,u.z+1));
		}
	}
	printf("%d\n",ans);
	return 0;
}
  