#include <bits/stdc++.h>
using namespace std;
int n;
struct node{
	int x,y;
}a[2600],b[2600];
bool gh[60][60];
bool vis[60][60];
queue<node> q;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
node s,t;
int bfs(node p,node* h){
	while (!q.empty()) q.pop();
	memset(vis,0,sizeof vis);
	q.push(p);
	int cnt=0;
	while (!q.empty()){
		node po=q.front();
		h[++cnt]=po;
		q.pop();
		for (int i=0;i<4;i++){
			int tx=po.x+dx[i],ty=po.y+dy[i];
			if (tx<=0||tx>n||ty<=0||ty>n) continue;
			if (!gh[tx][ty]&&!vis[tx][ty]) vis[tx][ty]=1,q.push({tx,ty});
		}
	}
	return cnt;
}
int main(){
	cin>>n;
	cin>>s.x>>s.y;
	cin>>t.x>>t.y;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			char cc;
			cin>>cc;
			if (cc=='1') gh[i][j]=1;
		}
	}
	int c1=bfs(s,a);
	int c2=bfs(t,b);
	int mi=1e9;
	for (int i=1;i<=c1;i++){
		for (int j=1;j<=c2;j++){
			mi=min(mi,(a[i].x-b[j].x)*(a[i].x-b[j].x)+(a[i].y-b[j].y)*(a[i].y-b[j].y));
		}
	}
	cout<<mi<<endl;
	return 0;
}