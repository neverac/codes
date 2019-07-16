#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std; 
typedef long long ll;
int n;
int a[105];
int s[105];
int dp[105][105];
int mmp[105][105];
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		memset(s,0,sizeof(s));
		memset(dp,0,sizeof(dp));
		memset(mmp,0,sizeof(mmp));
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			s[i]=s[i-1]+a[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				mmp[i][j] = (s[j]-s[i-1])%100;
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j+i<=n;j++)
			{
				int k=j+i;
				dp[j][k]=inf;
				for(int l=j;l<k;l++)
				dp[j][k]=min(dp[j][k],dp[j][l]+dp[l+1][k]+mmp[j][l]*mmp[l+1][k]);
			}
		}
		cout << dp[1][n] << endl;
	}
    return 0;
}