#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n,l,r;
int a[1005][1005];
int ha[1005][1005];
int le[1005][1005];
int res[1005][1005];
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	memset(a,0x3f,sizeof(a));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			res[i][j] = 1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i][j]==a[i][j-1]+1)
			{
				ha[i][j]=ha[i][j-1]+1;
			}
			else ha[i][j]=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[j][i]==a[j-1][i]+1)
			{
				le[j][i]=le[j-1][i]+1;
			}
			else le[j][i]=1;
		}
	}

	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(ha[i][j]>=ha[i-1][j-1]+1&&le[i][j]>=le[i-1][j-1]+1&&a[i][j]==a[i-1][j-1]+2)
			{
				res[i][j]=res[i-1][j-1]+1;
				ans=max(ans,res[i][j]);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*
4
1 0 3 4
2 3 4 5
3 4 5 6
4 0 6 0
 */