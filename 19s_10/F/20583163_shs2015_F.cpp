#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int SIZEN = 1010;
int N,M,S,T;
struct Link{
	int to,next;
}link[SIZEN * 2];
int head[SIZEN] = {0},tot = 0;
void add(int from,int to){
	link[++tot].to = to;
	link[tot].next = head[from];
	head[from] = tot;
}
#include <queue>
queue<int> q;
int diss[SIZEN] = {0};
int dist[SIZEN] = {0};
bool flag[SIZEN] = {0};
bool have[SIZEN][SIZEN] = {0};
void BFSs(int x){
	memset(diss,0x3f,sizeof diss);
	diss[x] = 0;
	q.push(x);
	while(!q.empty()){
		x = q.front();
		q.pop();
		for(int i = head[x];i;i=link[i].next){
			if(diss[link[i].to] != 0x3f3f3f3f)continue;
			diss[link[i].to] = diss[x] + 1;
			q.push(link[i].to);
		}
	}
}
void BFSt(int x){
	memset(dist,0x3f,sizeof dist);
	dist[x] = 0;
	q.push(x);
	while(!q.empty()){
		x = q.front();
		q.pop();
		for(int i = head[x];i;i=link[i].next){
			if(dist[link[i].to] != 0x3f3f3f3f)continue;
			dist[link[i].to] = dist[x] + 1;
			q.push(link[i].to);
		}
	}
}
int main(){
	scanf("%d%d%d%d",&N,&M,&S,&T);
	for(int i = 1;i <= M;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
		have[a][b] = have[b][a] = true;
	}
	BFSs(S);
	BFSt(T);
	int now = diss[T];
//	for(int i = 1;i <= N;i++)printf("(%d %d)\n",diss[i],dist[i]);
	int ans = 0;
	for(int i = 1;i <= N;i++){
		for(int j = i + 1;j <= N;j++){
			if(have[i][j])continue;
			if(diss[i] + dist[j] + 1 < now || diss[j] + dist[i] + 1 < now)continue;
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}