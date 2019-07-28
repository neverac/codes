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

#define N 55
int g[N][N], vis[N][N];
int n, r1, c1, r2, c2;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int flag;
void dfs(int nowx, int nowy, int id){
	vis[nowx][nowy] = id;
	int i,j,k,nx,ny;
	for(i = 0; i < 4; i++){
		nx = nowx + dx[i];
		ny = nowy + dy[i];
		if(nx <= 0 || nx > n || ny <= 0 || ny > n) continue;
		if(vis[nx][ny] == 3 - id){
			flag = 1;
		}
		if(vis[nx][ny] == -1 && g[nx][ny] == 0){
			dfs(nx, ny, id);
		}
	}
	return ;
}

void init(){
	int i,j,k;
	scanf("%d%d", &r1, &c1);
	scanf("%d%d", &r2, &c2);
	for(i = 1; i <= n; i++){
		char s[N];
		scanf("%s", s + 1);
		for(j = 1; j <= n; j++){
			g[i][j] = s[j] - '0';
			vis[i][j] = -1;
		}
	}
	flag = 0;
	if(r1 == r2 && c1 == c2) flag = 1;
}

int x3[N * N], y3[N * N];
int x2[N * N], y2[N * N];
int t1, t2;

void solve(){
	dfs(r1, c1, 1);
	dfs(r2, c2, 2);
	int i,j,k;
	if(flag == 1){
		printf("0\n");
		return ;
	}
	t1 = t2 = 0;
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			if(vis[i][j] == 1){
				x3[++t1] = i;
				y3[t1] = j;
			}
			else if(vis[i][j] == 2){
				x2[++t2] = i;
				y2[t2] = j;
			}
		}
	}
//	for(i = 1; i <= t1; i++){
//		cout<<x3[i]<<' '<<y3[i]<<endl;
//	}
//	cout<<endl;
//	for(i = 1; i <= t2; i++){
//		cout<<x2[i]<<' '<<y2[i]<<endl;
//	}
	int ans = 10000000;
	for(i = 1; i <= t1; i++){
		for(j = 1; j <= t2; j++){
			int s = (x3[i] - x2[j]) * (x3[i] - x2[j]) + (y3[i] - y2[j]) * (y3[i] - y2[j]);
			//cout<<s<<endl;
			ans = min(ans, s);
		}
	}
	printf("%d\n", ans);
	return ;
}

int main(){
	int i,j,k;
	cin>>n;
	init();
	solve();
	return 0;
}
/*
5
1 1
1 1
01111
11111
11111
11111
11111
5
1 1
1 2
00111
11111
11111
11111
11000
*/