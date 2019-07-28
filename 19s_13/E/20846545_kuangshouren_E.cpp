#include<iostream>
#include<cstring>
using namespace std;
int n,m;int num[5007],dis[20007];short b[5007][20007];
int main()
{
	memset(dis,0x3f,sizeof(dis));
	cin>>n>>m;
	for(int i=1;i<=m;++i)
	{int x,y;cin>>x>>y;
	++num[x];b[x][num[x]]=y;}
	for(int i=1;i<=n;++i)
	{
		if(num[i]==0){dis[i]=0;continue;}
		for(int j=1;j<=num[i];++j)
		{
			dis[i]=min(dis[i],(n+b[i][j]-i)%n);
		}
		dis[i]+=(num[i]-1)*n;
	}
	
for(int i=1;i<=n;++i)
{
	int c[10007]={0};
	int maxn=0;
	for(int j=1;j<=n;++j)
	{
		if(dis[j]==0)
		{c[j]=0;continue;}
		c[j]=dis[j]+(j+n-i)%n;
		maxn=max(maxn,c[j]);
	}
	
cout<<maxn<<" ";
}
return 0;
}