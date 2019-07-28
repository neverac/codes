#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
int n,m;
int mp[205][205];
int cnt[205];
int main(){
	int a,b;
    while(scanf("%d",&n)!=EOF&&n)
    {
    	scanf("%d",&m);
    	memset(mp,inf,sizeof(mp));
    	memset(cnt,0,sizeof(cnt));
    	for(int i=1;i<=m;i++)
    	{
    		scanf("%d%d",&a,&b);
    		mp[a][b]=mp[b][a]=1;
		}
		for(int k=0;k<=n;k++)
		{
			for(int i=0;i<=n;i++)
			{
				for(int j=0;j<=n;j++)
				{
					if(mp[i][j]>mp[i][k]+mp[k][j])
					{
						mp[i][j]=mp[i][k]+mp[k][j];
					}
				}
			}
		}
		for(int i=0;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(mp[i][j]!=inf)
				cnt[mp[i][j]]+=2;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(cnt[i])
			{
				printf("%d %d\n",i,cnt[i]);
			}
		}
	}
    return 0;
}



 