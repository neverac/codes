#include<bits/stdc++.h>
using namespace std;
char s[500010],a[500010],b[500010];
int main()
{
	int n,m,i,j,ii,now;
	bool pd;
	scanf("%s",s+1);
	n=strlen(s+1);
	m=(n+1)/2;ii=n;
	for(i=1;i<=m;i++)
	{
		a[i]=s[i];
		b[i]=s[ii];ii--;
	}
	for(i=1;i<=m;i++)
	{
		if(a[i]==b[i])continue;
		else
		{
			pd=false;
			for(j=i+1;j<=m;j++)
			{
				if(a[j]!=b[j-1]){pd=true;break;}
			}
			if(pd==false)
			{
				now=i;while(now>1&&a[now]==a[now-1])now--;
				printf("%d",now);
				return 0;
			}
			
			pd=false;
			for(j=i+1;j<=m;j++)
			{
				if(b[j]!=a[j-1]){pd=true;break;}
			}
			if(pd==false)
			{
				now=i;while(now<m&&b[now]==b[now+1])now++;
				now=n-now+1;
				printf("%d",now);
				return 0;
			}
		}
	}
	now=(n+1)/2;
	while(now>1&&a[now]==a[now-1])now--;
	printf("%d",now);
	return 0;
}