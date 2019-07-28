#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

#define LL long long
#define ULL unsigned long long
#define INF 0x7fffffff

LL read(){
	LL x=0,f=1; char ch=getchar();
	while (ch<'0' || ch>'9') {if (ch=='-') f=-1; ch=getchar();}
	while (ch>='0' && ch<='9') {x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}

#define Pa pair<int,int>
#define MP make_pair

#define MAXN 200010

int N,a[200010],id[100][100],loc[100010][2],idn;
int f[100010];
char mp[100][100];
int F(int x){
	if (f[x]==x) return x; else return f[x]=F(f[x]);
}
void merge(int x,int y){
	int fx=F(x),fy=F(y);
	if (fx==fy) return;
	f[fx]=fy;
}
int dx[4]={0,0,-1,1},dy[4]={-1,1,0,0};
int main(){
	N=read();
	int R1=read(),C1=read();
	int R2=read(),C2=read();
	for (int i=1; i<=N; i++) scanf("%s",mp[i]+1);
	for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) id[i][j]=++idn;
	for (int i=1; i<=idn; i++) f[i]=i;
	for (int i=1; i<=N; i++){
		for (int j=1; j<=N; j++){
			int x = id[i][j];
			if (mp[i][j]=='1') continue;
			for (int d=0; d<4; d++){
				int ti=i+dx[d],tj=j+dy[d];
				if (ti<1 || ti>N) continue;
				if (tj<1 || tj>N) continue;
				if (mp[ti][tj]=='1') continue;
				int y = id[i+dx[d]][j+dy[d]];
				merge(x,y);		
			}
		}
	}
	int s=id[R1][C1],t=id[R2][C2];
	if (F(s)==F(t)){
		puts("0");
		return 0;
	} else {
		int ans=50*50*2;
		for (int i=1; i<=N; i++){
			for (int j=1; j<=N; j++){
				int x = id[i][j];
				if (mp[i][j]=='1') continue;
				if (F(x)!=F(s)) continue;
				for (int ii=1; ii<=N; ii++){
					for (int jj=1; jj<=N; jj++){
						int y = id[ii][jj];
						if (mp[ii][jj]=='1') continue;
						if (F(y)!=F(t)) continue;
						ans=min(ans,(ii-i)*(ii-i)+(jj-j)*(jj-j));
					}
				}
			}
		}
		printf("%d\n",ans);
		return 0;
	}
	return 0;
}

/*
5
1 1
5 5
00001
11111
00111
00110
00110

3
1 3
3 1
010
101
010
*/
	