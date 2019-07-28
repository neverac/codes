#include <bits/stdc++.h>
using namespace std;
int n;
long long dp[100005];
long long x,y;
int mp[100005][2]={};
int main()
{
	scanf("%d",&n);
	memset(mp,0,sizeof(mp));
	for(int i=0;i<n*2;i++)
	{
		scanf("%lld",&x);
		if(!mp[x][0]) mp[x][0]=i;
		else mp[x][1]=i;
	}
	for(int i=1;i<=n;i++)
	{
		x=abs(mp[i][0]-mp[i-1][0])+abs(mp[i][1]-mp[i-1][1]);
		y=abs(mp[i][0]-mp[i-1][1])+abs(mp[i][1]-mp[i-1][0]);
		dp[i]=dp[i-1]+(long long)min(x,y);
	}
	cout << dp[n] << endl;
    return 0;
}