#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;
#define ll long long 
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48,ch=getchar();}
	return x*f;
}
const int maxn = 200100;
struct edge{int to,next;}e[maxn*2];
int tot,head[maxn];
void add(int u,int v){
	e[++tot].to=v;
	e[tot].next=head[u];
	head[u]=tot;
}
int deep[maxn],f[maxn];
void dfs(int u,int fa){
	for(int i=head[u];i;i=e[i].next){
		int to=e[i].to;
		if(to==fa) continue;
		deep[to]=deep[u]+1;
		dfs(to,u);
	}
}
int main(){
	
	int n=read();
	for(int i=1;i<n;i++){
		int a=read(),b=read();
		add(a,b);add(b,a);
	}
	dfs(1,0);
	int mx=0;
	for(int i=1;i<=n;i++){
		if(deep[i]>deep[mx]) mx=i;
	}
	memset(deep,0,sizeof deep);
	deep[mx]=1;
	dfs(mx,0);
	int len=0;
	for(int i=1;i<=n;i++){
		if(deep[i]>len) len=deep[i];
	}
	
	f[0]=1,f[1]=1,f[2]=0;
	for(int i=3;i<=len;i++){
		if((f[i-1])&&(f[i-2])) f[i]=0;
		else f[i]=1;
	}
	if(f[len]) printf("First\n");
	else printf("Second\n");
	return 0;
}
  