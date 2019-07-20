#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
const int maxn=1010;
using namespace std;
int n,m,s,t;
int G[maxn][maxn],q[maxn];
int d[2][maxn],ans;

inline int read(){
	char ch;
	int f=1,res=0;
	while((ch=getchar())<'0'||ch>'9')
		if(ch=='-') f=-1;
	while(ch>='0'&&ch<='9')
	{
		res=(res<<1)+(res<<3)+(ch^48);//注意位运算的优先级别
		ch=getchar();
	}
	return f*res;
}

void bfs(int s,int t,int p){
	//memset(d,0x3f,sizeof(d));
	 for (int i=1;i<=n;i++) d[p][i] = INF;
	int f=0,r=1;q[1]=s;d[p][s] = 0;
	
	while (f<r){
		int u=q[++f];
		for (int v=1;v<=n;v++){
			if (G[u][v]){
				if (d[p][u] + 1 <d[p][v]){
					d[p][v] = d[p][u]+1;
					q[++r]=v;
				}
			}
		}
	}
}
int main(){
	ans=0;
	memset(G,0,sizeof(G));
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >>n >> m >>s >>t;
	//n=read();m=read();s=read();t=read();
	while (m--){
		int u,v;
		cin >> u >> v;
		G[u][v] = G[v][u] =1;
	}
	bfs(s,t,0);
	bfs(t,s,1);
	//for (int i=1;i<=n;i++)cout <<d[0][i]<<"&"<<d[1][i] << endl;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if ( !G[i][j] && i!=j) {
				if (d[0][i]+d[1][j]+1 >=d[0][t] && d[0][j] + d[1][i]+1 >=d[0][t]) ans++;//,cout << "%%"<<i <<' '<< j <<endl;
			}
	cout << ans/2;

}