#include<bits/stdc++.h>
#define LL long long
using namespace std;
struct node
{
	LL k1,k2;
}a[200010];
LL bj[200010];
bool cmp(node aa,node bb){return aa.k1>bb.k1;}
int main()
{
	LL n,m,k,i,ans,gs,kk;
	scanf("%lld %lld %lld",&n,&m,&k);
	for(i=1;i<=n;i++){scanf("%lld",&a[i].k1);a[i].k2=i;}
	sort(a+1,a+n+1,cmp);
	
	ans=0LL;
	for(i=1;i<=m*k;i++){bj[a[i].k2]=1;ans+=a[i].k1;}
	printf("%lld\n",ans);
	
	gs=0LL;kk=0LL;
	for(i=1;i<=n;i++)
	{
		if(bj[i]==1LL)
		{
			gs++;
			if(gs==m){printf("%lld ",i);gs=0LL;kk++;}
			if(kk==k-1LL)break;
		}
	}
	return 0;
}