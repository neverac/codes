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
#define M 2020
#define inf 100000

struct node{
	int v, w, next;
}e[M];
int head[N];
int dist1[N], dist2[N], inq1[N], inq2[N];
int n, m, s, t, len;
int g[N][N];
void add_edge(int u,int v){
	e[len].v = v;
	e[len].w = 1;
	e[len].next = head[u];
	head[u] = len++;
	return ;
}
void spfa1(int x){
	int i,j,k,u,v,w;
	queue<int> Q;
	for(i = 1; i <= n; i++){
		dist1[i] = inf; inq1[i] = 0;
	}
	Q.push(x);
	dist1[x] = 0;
	inq1[x] = 1;
	while(!Q.empty()){
		u = Q.front();
		Q.pop();
		inq1[u] = 0;
		//cout<<u<<endl;
		for(i = head[u]; i != -1; i = e[i].next){
			v = e[i].v; w = e[i].w;
			if(dist1[v] > dist1[u] + w){
				dist1[v] = dist1[u] + w;
				if(!inq1[v]){
					Q.push(v);
					inq1[v] = 1;
				}
			}
		}
	}
	//for(i=1;i<=n;i++)cout<<dist1[i]<<' ';
	//cout<<endl;
	
}
void spfa2(int x){
	int i,j,k,u,v,w;
	queue<int> Q;
	for(i = 1; i <= n; i++){
		dist2[i] = inf; inq2[i] = 0;
	}
	Q.push(x);
	dist2[x] = 0;
	inq2[x] = 1;
	while(!Q.empty()){
		u = Q.front();
		Q.pop();
		inq2[u] = 0;
		for(i = head[u]; i != -1; i = e[i].next){
			v = e[i].v; w = e[i].w;
			if(dist2[v] > dist2[u] + w){
				dist2[v] = dist2[u] + w;
				if(!inq2[v]){
					Q.push(v);
					inq2[v] = 1;
				}
			}
		}
	}
}
void init(){
	int i,j,k,u,v;
	cin>>n>>m>>s>>t;
	len = 0;
	memset(head, -1, sizeof(head));
	for(i = 1; i <= m; i++){
		scanf("%d%d", &u, &v);
		add_edge(u, v);
		add_edge(v, u);
		g[u][v] = g[v][u] = 1;
	}
	spfa1(s);
	spfa2(t);
	return ;
}
void solve(){
	int i, j, ans = 0;
//	for(i=1;i<=n;i++)cout<<dist1[i]<<' ';
//	cout<<endl;
//	for(i=1;i<=n;i++)cout<<dist2[i]<<' ';
//	cout<<endl;	
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			if(g[i][j] == 0 && i != j){
//				cout<<i<<' '<<j<<endl;
//				cout<<"d "<<dist1[i]<<' '<<dist2[j]<<' '<<dist1[t]<<endl;
				if(dist1[i] + 1 + dist2[j] >= dist1[t] && dist1[j] + 1 + dist2[i] >= dist1[t]) ans++;
			}
		}
	}
	printf("%d\n", ans/2);
}

int main(){
	init();
	solve();
	return 0;
}
