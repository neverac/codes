#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define LL long long
using namespace std;

const int maxn = 1e6+100;

bool vis[maxn];

int pri[maxn],tot=0;

void get_prime(int x)
{
	memset(vis,0,sizeof(vis));
	for(int i=2;i<=x;i++)
	{
		if(vis[i]) continue;
		pri[++tot]= i;
		for(int j=i;j<=x/i;j++) vis[i*j]= 1;
	}
}

int T;
LL n;
LL res[maxn],ctt,sum,ans;
int main()
{
	ios::sync_with_stdio(false);
	get_prime(1e6);
	cin>>T;
	while(T--)
	{
		cin>>n;
		LL cnt=0;ctt=0;ans=0;
		for(int i=1;i<=tot;i++)
		{
			cnt = 0;
			while(n%pri[i]==0)
			{
				cnt++;
				n/=pri[i];
			}
			if(cnt) res[++ctt] = cnt;
		}
		if(n!=1) res[++ctt] = 1;
		sum = 1;
		//for(int i=1;i<=ctt;i++) cout<<res[i]<<" ";
			//cout<<endl;
		for(int i=1;i<=ctt;i++)
		{
			sum*=(res[i]+1);
		}
		for(int i=1;i<=ctt;i++)
		{
			ans +=(res[i]*sum/(res[i]+1));
		}
		cout<<ans<<endl;
	}
	return 0;
}