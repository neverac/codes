#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define LL long long
using namespace std;

const int maxn = 1e6+100;

LL n,r,k,ans;
LL val[maxn],sum[maxn],cha[maxn];
bool check(LL x)
{
	memset(cha,0,sizeof(cha));
	LL res = k;
	for(int i=1;i<=n;i++)
	{
		cha[i]+=cha[i-1];
		LL bs = sum[i+r];
		if(i+r>n) bs = sum[n];
		if(i>r) bs -= sum[i-r-1];
		bs+=cha[i];
		if(bs<x){
			res-=(x-bs);
			cha[i]+=(x-bs);
			cha[i+2*r+1]-=(x-bs);
			if(res<0) return false;
		}
	}
	return true;
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>r>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>val[i];
		sum[i]=val[i];
		sum[i]+=sum[i-1];
	}
	LL l=0,r=6e18;
	while(l<=r)
	{
		LL mid = (l+r)>>1;//cout<<"Check:8080 : "<<mid<<endl;
		if(check(mid))
		{
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<ans<<endl;
	return 0;
}