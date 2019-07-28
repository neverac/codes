#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,m; 
int vis[500];
int d[500];
int main()
{
	int a,b;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	d[i]=inf;
	for(int i=1;i<=m;i++)
	{
		int dis;
		scanf("%d%d",&a,&b);
		vis[a]++;
		if(b>a) dis=b-a;
		else dis=n+b-a;
		d[a]=min(d[a],dis);
	}
	long long op=0;
	for(int i=1;i<=n;i++)
	{
		op=0;
		vis[n+i]=vis[i];
		d[n+i]=d[i];
		for(int j=0;j<n;j++)
		{
			if(vis[i+j])
			op=max(op,(long long)((vis[i+j]-1)*n+d[i+j]+j));
		}
		cout << op << " ";
	}
    return 0;
}