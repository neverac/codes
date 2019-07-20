#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL z[1000010],s[1000010],f[1000010];
int main()
{
	LL T,i,n,ans;
	scanf("%lld",&T);
	for(i=1;i<=1000000LL;i++)
	{
		z[i]=z[i-1]+i;
		s[i]=s[i-1]+z[i];
	}
	
	f[1]=0LL;
	f[2]=1LL;
	for(i=3LL;i<=1000000LL;i++)
	{
		f[i]=f[i-2LL]+z[i-1];
	}
	while(T--)
	{
		scanf("%lld",&n);
		ans=0LL;
		ans+=s[n];
		ans+=f[n];
		printf("%lld\n",ans);
	}
	return 0;
}