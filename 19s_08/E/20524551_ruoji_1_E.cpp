#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,T,i,a,t[10],ans,tt;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		memset(t,0,sizeof(t));
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a);
			t[a%3]++;
		}
		ans=0;
		ans+=t[0];
		tt=min(t[1],t[2]);
		ans+=tt;
		t[1]-=tt;t[2]-=tt;
		ans+=(t[1]/3)+(t[2]/3);
		printf("%d\n",ans);
	}
	return 0;
}