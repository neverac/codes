#include <bits/stdc++.h>
using namespace std;
int n,m;
bool gh[1100][1100];
int f[1100][1100];
bool vis[1100][1100];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
struct node{
	int x,y;
};
queue <node> q;
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	int cnt=0;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			char c;
			cin>>c;
			if (c=='#') {
				gh[i][j]=true;
				q.push({i,j});
				cnt++;
				vis[i][j]=true;
			}
		}
	}
	while (!q.empty()){
		node now=q.front();
		q.pop();
		for (int i=0;i<4;i++){
			int tx=now.x+dx[i],ty=now.y+dy[i];
			if (tx<=0||tx>n||ty<=0||ty>m) continue;
			if (!vis[tx][ty]) {
				cnt++;
				f[tx][ty]=f[now.x][now.y]+1;
				vis[tx][ty]=true;
				q.push({tx,ty});
			}
		}
	}
	int ans=0;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			ans=max(ans,f[i][j]);	
		}
	}
	cout<<ans<<endl;
	return 0;
		
}