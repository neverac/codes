#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m;int num[107],dis[207];int b[107][207];
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
	int c[107]={0};
	for(int j=1;j<=n;++j)
	{
		if(dis[j]==0)
		{c[j]=0;continue;}
		c[j]=dis[j]+(j+n-i)%n;
	}
	sort(c+1,c+n+1);
	cout<<c[n]<<" ";
}
return 0;
}