#include<iostream>
#include<cstring>
using namespace std;
char a[57][57];int b[57][57];bool v[57][57];
int n,x1,x2,Y1,y2;
void dfs(int x,int y,int z)
{
	if(a[x][y]=='1'||v[x][y]==1)return;
	v[x][y]=1;b[x][y]+=z;
	if(x!=n)dfs(x+1,y,z);
	if(x!=1)dfs(x-1,y,z);
	if(y!=n)dfs(x,y+1,z);
	if(y!=1)dfs(x,y-1,z);
}
int main()
{
	cin>>n;
	cin>>x1>>Y1;
	cin>>x2>>y2;
	for(int i=1;i<=n;++i)
	{for(int j=1;j<=n;++j)
	{cin>>a[i][j];}}
	dfs(x1,Y1,1);
	memset(v,0,sizeof(v));
	dfs(x2,y2,2);
	if(b[x1][Y1]==3)cout<<"0";
	else
	{
		int maxn=0x3f3f3f3f;
		for(int i=1;i<=n;++i)
		{for(int j=1;j<=n;++j)
		{
		if(b[i][j]!=1)continue;
		for(int k=1;k<=n;++k)
		{
		for(int l=1;l<=n;++l)
		{if(b[i][j]==1&&b[k][l]==2)
		{maxn=min(maxn,(i-k)*(i-k)+(j-l)*(j-l));}}}}}
		cout<<maxn;
	}
	return 0;
	
}