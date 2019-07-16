#include<bits/stdc++.h>
using namespace std;
int q0[1010],q1[1010];
char s[1010];
int main()
{
	int T,n,tot,i,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("\n%s",s+1);
		n=strlen(s+1);
		q0[0]=q1[0]=0;
		for(i=1;i<=n;i++)
		{
			q0[i]=q0[i-1]+(s[i]=='0');
			q1[i]=q1[i-1]+(s[i]=='1');
		}
		ans=(n-q1[n]);
		for(i=1;i<=n;i++)
		{
			tot=(i-q0[i])+((n-i)-(q1[n]-q1[i]));
			ans=min(ans,tot);
		}
		printf("%d\n",ans);
	}
	return 0;
}