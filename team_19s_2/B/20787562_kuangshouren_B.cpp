#include<iostream>
#include<cstdio>
using namespace std;
int a[307][307];int T,n;
int main()
{
	cin>>T;
	for(int w=1;w<=T;++w)
	{
		int maxn=0;
		cin>>n;
		for(int i=1;i<=n*(n-1)/2;++i)
		{int x,y,z;cin>>x>>y>>z;
		a[x][y]=z;a[y][x]=z;}
		for(int i=3;i<=n;++i)
		{for(int j=2;j<i;++j)
		{for(int k=1;k<j;++k)
		{maxn=max(maxn,a[i][j]+a[j][k]+a[k][i]);}}}
		cout<<maxn<<endl;
	}
	return 0;}