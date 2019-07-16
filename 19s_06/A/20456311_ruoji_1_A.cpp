#include<bits/stdc++.h>
#define ULL unsigned long long
#define INF 1e18
using namespace std;
ULL c1[11000],c2[11000],lcc;
void FJ(ULL b2)
{
	ULL bb=b2,b1,i;
	b1=(ULL)sqrt(bb);
	lcc=0ULL;
	for(i=2ULL;i<=b1;i++)
	{
		if(bb%i==0ULL)
		{
			c1[++lcc]=i;
			while(bb%i==0ULL)
			{
				c2[lcc]++;
				bb/=i;
			}
		}
	}
	if(bb!=1ULL)
	{
		c1[++lcc]=bb;
		c2[lcc]=1ULL;
	}
}
int main()
{
	ULL i,tot,ys,cf,n,b,ans;
	scanf("%llu %llu",&n,&b);
	
	FJ(b);
	
	//ans=INF;
	ans=-1ULL;
	for(i=1ULL;i<=lcc;i++)
	{
		ys=c1[i];cf=ys;
		tot=0ULL;
		while(1)
		{
			if(cf>n)break;
			tot+=(ULL)(n/cf);
			if(cf>n/ys)break;
			cf*=ys;
		}
		if(ans==-1ULL)ans=tot/c2[i];
		else ans=min(ans,tot/c2[i]);
	}
	printf("%llu",ans);
	return 0;
} 