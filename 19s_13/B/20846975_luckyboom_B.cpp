#include<bits/stdc++.h>
using namespace std;
int const maxn=1e5+100;
int n;
long long dis[3][maxn];
long long dp[maxn][3];
bool vis[maxn];
int main(){
	memset(vis,0,sizeof(vis));
	scanf("%d",&n);
	int z=n<<1,m;
	for(int i=1;i<=z;i++){
		scanf("%lld",&m);
		if(vis[m])dis[1][m]=i;
		else {dis[0][m]=i;vis[m]=1;}
	}
	dp[1][0]=dis[0][1]+dis[1][1]-2;
	dp[1][1]=dis[0][1]+dis[1][1]-2;
	int f00,f01,f11,f10;
	for(int i=2;i<=n;i++){
		f00=abs(dis[0][i-1]-dis[0][i]);
		f01=abs(dis[0][i-1]-dis[1][i]);
		f11=abs(dis[1][i-1]-dis[1][i]);
		f10=abs(dis[1][i-1]-dis[0][i]);
		dp[i][0]=min(dp[i-1][0]+f00+f11,dp[i-1][1]+f10+f01);
		dp[i][1]=min(dp[i-1][0]+f01+f10,dp[i-1][1]+f11+f00);
	//cout<<dp[i][0]<<' '<<dp[i][1]<<endl;
	}
	long long ans=min(dp[n][0],dp[n][1]);
	printf("%lld\n",ans);
	return 0;
}