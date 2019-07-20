#include<bits/stdc++.h>
#define MAX 2147483647 
int d1[1005],d2[1005],vis[1005],d,ans;
int n,m,s,t;

struct node
{
	int d,nxt;
}e[2005];
int f[1005];

void dijkstra1()//板子 
{
	memset(vis,0,sizeof(vis));
	memset(d1,0x3f,sizeof(d1)); 
	d1[s]=0;
	for(int k=0;k<n;k++)
	{
		int mint=MAX,u=0;
		for(int i=1;i<=n;i++)
		{
			if(!vis[i]&&d1[i]<mint)
			{
				mint=d1[i];
				u=i;
			}
		}
			
		vis[u]=1;//加入边集 
		for(int i=f[u];i;i=e[i].nxt)
		{
			int v=e[i].d;
			if(d1[v]>d1[u]+1)
		    d1[v]=d1[u]+1;
		}
	}
}

void dijkstra2()//板子 
{
	memset(vis,0,sizeof(vis));
	memset(d2,0x3f,sizeof(d2)); 
	d2[t]=0;
	for(int k=0;k<n;k++)
	{
		int mint=MAX,u=0;
		for(int i=1;i<=n;i++)
		{
			if(!vis[i]&&d2[i]<mint)
			{
				mint=d2[i];
				u=i;
			}
		}
			
		vis[u]=1;//加入边集 
		for(int i=f[u];i;i=e[i].nxt)
		{
			int v=e[i].d;
			if(d2[v]>d2[u]+1)
		    d2[v]=d2[u]+1;
		}
	}
}

int main()
{
	
	scanf("%d%d%d%d",&n,&m,&s,&t);
	int tot=0;
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		tot++;
		e[tot].d=b;
		e[tot].nxt=f[a];
		f[a]=tot;
		tot++;
		e[tot].d=a;
		e[tot].nxt=f[b];
		f[b]=tot;
	}
	dijkstra1();
	dijkstra2();
	
	d=d1[t];

	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
	   {
			if(d1[i]+d2[j]+1>=d&&d1[j]+d2[i]+1>=d)
		    ans++;
//		    printf("%d %d\n",d1[i],d2[j]);
       }
	}
	printf("%d\n",ans-m);
	return 0;
} 