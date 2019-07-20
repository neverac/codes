#include<bits/stdc++.h>
#define INF 1e9
using namespace std;
int a[500010];
int main()
{
	int n,i,t[10]={0},ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==4)a[i]=1;
		else if(a[i]==8)a[i]=2;
		else if(a[i]==15)a[i]=3;
		else if(a[i]==16)a[i]=4;
		else if(a[i]==23)a[i]=5;
		else a[i]=6;
	}
	t[0]=INF;
	for(i=1;i<=n;i++)
	{
		if(t[a[i]-1]>0)
		{
			t[a[i]-1]--;
			t[a[i]]++;
			if(a[i]==6)
			{
				ans++;
			}
		}
	}
	printf("%d",n-ans*6);
	return 0;
}