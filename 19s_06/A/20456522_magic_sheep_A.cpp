#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#define LL long long
using namespace std;
const int maxn = 1e6+50000;
LL n,b,pri[maxn],yin[maxn],sum[maxn];
bool vis[maxn];
int tot;
void get_prime()
{
	for(int i=2;i<=1e6+100;i++)
	{
		if(vis[i]) continue;
		else pri[++tot]=i;
		int cnt=1;
		while(i*cnt<=1e6+100)
		{
			vis[i*cnt]=true;
			cnt++;
		}
	}
}
int main()
{
	get_prime();
	cin>>n>>b;
	int res=0;
	LL cur=b;
	for(int j=1;j<=tot;j++)
	{
		int cnt=0;
		while(cur%pri[j]==0)
		{
			cur/=pri[j];
			cnt++;
		}
		if(cnt)
		{
			yin[++res] = pri[j];
			sum[res] = cnt;
		}
	}
	if(cur!=1){
		yin[++res] = cur;
		sum[res] = 1;
	}
	LL ans = 1e18;
	for(int i=1;i<=res;i++)
	{
		LL res1=0,c1=yin[i];
		while(c1<=n)
		{
			res1+=n/c1;
			if(n/c1 < yin[i]) break;
			c1*=yin[i];
		}
		ans=min(ans,res1/sum[i]);
	}
	cout<<ans<<endl;
	return 0;
}
/*
5 11
 */