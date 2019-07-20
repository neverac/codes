#include<bits/stdc++.h>
#define MOD 998244353
#define MAXN 200010
#define LL long long
using namespace std;
char a[MAXN];
int main()
{
	int n,i,nn,n1;
	LL ans;
	scanf("%d",&n);
	scanf("\n%s",a+1);
	
	ans=0LL;nn=n;
	for(i=n-1;i>=1;i--){if(a[i]!=a[n])break;else nn=i;}
	if(nn==1LL)
	{
		printf("%lld",(n*(1LL+n)/2LL)%MOD);
		return 0;
	}
	ans=(ans+(LL)(n-nn+1LL+1LL))%MOD;
	
	if(a[1]!=a[n])
	{
		for(i=2;i<=n;i++)if(a[i]==a[1])ans=(ans+1LL)%MOD;else break;
		ans=(ans+1LL)%MOD;
	}
	else
	{
		for(i=2;i<=n;i++)
		{
			/*if(a[1]!=a[n])
			{
				ans=(ans+1LL)%MOD;
				break;
			}
			else*/
			{
				n1=max(nn,i);
				ans=(ans+(n-n1+1LL+1LL))%MOD;
			}
			if(a[i]!=a[1])break;
		}
	}
	printf("%lld",(ans%MOD+MOD)%MOD);
	return 0;
}