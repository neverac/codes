#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
const ll inf = 1e18+5;
ll n,b;
ll prime[1000005];
ll cnt[1000005];
ll getsum(ll a,ll d)
{
	ll sum=0;
	while(a>0)
	{
		sum+=a/d;
		a/=d;
	}
	return sum;
}
ll min1(ll a,ll d)
{
	if(a>d) return d;
}
int main()
{
	scanf("%lld%lld",&n,&b);
	ll t=0;
	for(ll i=2;i*i<=b;i++)
	{
		while(b%i==0)
		{
			prime[t]=i;
			cnt[t]++;
			b/=i;
		}
		if(cnt[t]!=0) t++;
	}
    if(b>1) prime[t]=b,cnt[t++]=1;
    ll op=inf;
    for(ll i=0;i<t;i++)
    {
    	op=min1(op,getsum(n,prime[i])/cnt[i]);
	}
	printf("%lld\n",op);
    return 0;
}