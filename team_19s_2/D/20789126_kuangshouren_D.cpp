#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[207][207];
int d[207];
int n,m,T;
int main()
{
	for(;;)
	{
		int maxn=0;
		memset(a,0x3f,sizeof(a));
		memset(d,0,sizeof(d));
		cin>>n;
		if(n==0)break;
		cin>>m;
		for(int i=1;i<=m;++i)
		{
			int x,y;cin>>x>>y;
			a[x+1][y+1]=1;a[y+1][x+1]=1;
		}
		for(int k=1;k<=n;++k)
		{for(int i=1;i<=n;++i)
		{for(int j=1;j<=n;++j)
		{if(a[i][k]+a[k][j]<a[i][j])
		{a[i][j]=a[i][k]+a[k][j];}}}}
		for(int i=1;i<=n;++i)
		{for(int j=1;j<=n;++j)
		{if(i!=j)
		{++d[a[i][j]];
		maxn=max(maxn,a[i][j]);}}}
		for(int i=1;i<=maxn;++i)cout<<i<<" "<<d[i]<<endl;
	}
	return 0;
}