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

#define N 400040
struct edge{
	int v, next;
}e[N];
int head[N];
int vis[N];
int n, len, depth, depid;
void add_edge(int u, int v){
	e[len].v = v;
	e[len].next = head[u];
	head[u] = len++;
}
void dfs(int now, int d){
	if(depth < d){
		depth = d;
		depid = now;
	}
	int i;
	vis[now] = 1;
	for(i = head[now]; i != -1; i =e[i].next){
		int v = e[i].v;
		if(vis[v]) continue;
		dfs(v, d + 1);
	}
	return ;
}

int main(){
	int i,u,v;
	memset(head, -1, sizeof(head));
	len = 0;
	cin>>n;
	for(i = 1; i <= n - 1; i++){
		scanf("%d%d", &u, &v);
		add_edge(u, v);
		add_edge(v, u);
	}
	depth = 0;
	dfs(1, 1);
	memset(vis, 0, sizeof(vis));
	depth = 0;
	dfs(depid, 1);
	if(depth % 3 == 2){
		printf("Second\n");
	}
	else printf("First\n");

	return 0;
}
