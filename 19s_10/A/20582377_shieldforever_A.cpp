#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<string>
#include<iomanip>
#include<queue>

using namespace std;
#define N 1010
struct node{
	int x,y;
};
char g[N][N];
int vis[N][N];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int n,m;
int bfs(){
	queue<node> Q;
	int i,j,k;
	int depth = 0, tot = 0;
	for(i = 1; i <= n; i++){
		for(j = 1; j <= m; j++){
			if(g[i][j] == '#'){
				node u = {i, j};
				vis[i][j] = 1;
				Q.push(u);
				tot++;
			}
		}
	}
	while(!Q.empty()){
		if(tot == n * m) return depth;
		int len = Q.size();
		while(len--){
			node u = Q.front();
			Q.pop();
			for(i = 0; i < 4; i++){
				int nx = u.x + dx[i];
				int ny = u.y + dy[i];
				if(nx < 1 || ny < 1 || nx > n || ny > m) continue;
				if(vis[nx][ny]) continue;
				node v = {nx, ny};
				Q.push(v);
				vis[nx][ny] = 1;
				tot++;
			}			
		}
		depth++;
	}
	return depth;
}


int main(){
	cin>>n>>m;
	int i,j,k;
	for(i = 1; i <= n; i++){
		scanf("%s", g[i] + 1);
	}
	printf("%d\n", bfs());
	
	return 0;
}
