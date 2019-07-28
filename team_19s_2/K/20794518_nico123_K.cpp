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

int c[30], head[30], tot;
int n, m, ans;
struct edge{
	int v, nxt;
}e[10000];
//void solve(){
//	int i,k;
//	for(i = 0; i < n; i++){
//		memset(b, 0, sizeof(b));
//		for(k = 0; k < n; k++){
//			if(e[i][k] && c[k] != -1){
//				b[c[k]] = 1;
//			}
//		}
//		for(k = 0; k <= i; k++){
//			if(!b[k]) break;
//		}
//		c[i] = k;
//	}
//	for(i = 0; i < n; i++){
//		if(ans < c[i]) ans = c[i];
//	}
//	ans++;
//	if(ans <= 3)printf("Y\n");
//	else printf("N\n");
//	return ;
//} 

void add_edge(int u, int v){
	e[tot].v = v;
	e[tot].nxt = head[u];
	head[u] = tot++;
}


bool check(int i, int color){
	for(int j = head[i]; j != -1; j = e[j].nxt){
		if(color == c[e[j].v]) return false;
	}
	return true;
}

void dfs(int now){
	int i,j,k;
	if(now == n){
		int t = 0;
		for(j = 0; j < n; j++){
			if(c[j] > t) t = c[j];
		}
		ans = min(ans, t);
		return ;
	}
	for(i = 1; i <= 3; i++){
		if(check(now, i)){
			c[now] = i;
			dfs(now + 1);
			c[now] = -1;
		}
	}
}

void init(){
	int i,j,k;
	cin>>n>>m;
	tot = 0;
	memset(head, -1, sizeof(head));
	memset(c, -1, sizeof(c));
	ans = 5;
	for(i = 1; i <= m; i++){
		scanf("%d%d", &j, &k);
		add_edge(j, k); add_edge(k, j);
	}
	return ;
}

int main(){
	int T;
	cin>>T;
	while(T--){
		init();
		//solve();
		dfs(0);
		//cout<<ans<<endl;
		if(ans <= 3)printf("Y\n");
		else printf("N\n");
	}

	return 0;
}
