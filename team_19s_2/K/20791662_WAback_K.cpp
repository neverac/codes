#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define INF 0x7fffffff

LL read(){
	LL x=0,f=1; char ch=getchar();
	while (ch<'0' || ch>'9') {if (ch=='-') f=-1; ch=getchar();}
	while (ch>='0' && ch<='9') {x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}

#define MAXN 10010

bool flag;
int mp[30][30],col[30],N,M;
inline void dfs(int x,int dep){
	
	if (flag) return;
	for (int y=1; y<x; y++){
		if (mp[x][y] && col[x]==col[y]) return;
	}
	//printf("debug %d %d\n",x,dep);
	if (dep==N){
		flag=1;
		return;
	}
	int y=x+1;
	for (int i=1; i<=3; i++){
		col[y]=i;
		dfs(y,dep+1);
		col[y]=0;
	}
}

int main(){
	int cas=read();
	while (cas--){
		N=read(),M=read();
		memset(mp,0,sizeof(mp));
		memset(col,0,sizeof(col));
		
		for (int i=1; i<=M; i++){
			int u=read(),v=read(); u++,v++;
			mp[u][v]=1; mp[v][u]=1;
		}
		flag=0;
		for (int i=1; i<=3; i++){
			col[1]=i;
			dfs(1,1);
			if (flag) break;
		}
		if (flag) puts("Y");
		else puts("N");
	}
	return 0;
}

/*
4
6
6
0 3
1 5
3 2
2 5
0 4
1 0
7
12
6 5
0 3
2 6
3 5
5 0
0 4
4 5
6 3
1 4
1 2
3 4
2 3
7
8
6 5
0 3
2 6
3 5
1 4
1 2
3 4
2 3
6
9
0 1
1 2
2 3
5 2
5 3
3 4
2 4
1 4
4 5
*/
	