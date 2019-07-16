#include<bits/stdc++.h>
#define LL long long
#define INF 1e16
using namespace std;
LL s[110],a[110],f[110][110];
LL Sum(LL l,LL r){return ((s[r]-s[l-1])%100LL+100LL)%100LL;}
LL dfs(LL l,LL r)
{
	LL i,s1,s2;
	if(l>r)return INF;
	if(f[l][r]!=INF)return f[l][r];
	if(l+1LL==r)return f[l][r]=a[l]*a[r];
	if(l==r)return f[l][r]=0LL;
	for(i=l;i<r;i++)
	{
		s1=dfs(l,i);s2=dfs(i+1LL,r);
		f[l][r]=min(f[l][r],s1+s2+Sum(l,i)*Sum(i+1LL,r));
	}
	return f[l][r];
}
int main()
{
	LL n,i,j;
	while(scanf("%lld",&n)!=EOF)
	{
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		s[0]=0LL;for(i=1;i<=n;i++)s[i]=s[i-1]+a[i];
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)f[i][j]=INF;
		}
		printf("%lld\n",dfs(1,n));
	}
	return 0;
}