#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;
#define ll long long 
ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48,ch=getchar();}
	return x*f;
}
const int maxn = 501000;
ll n,R,c[maxn],s[maxn],b[maxn],K;

bool check(ll x){
	memset(b,0,sizeof b);
	//printf("\n%d\n",x);
	ll add=K,sum=0;
	for(ll i=1;i<=n;i++){
		ll now=s[min(i+R,n)]-s[max(i-R-1,0LL)];
		//printf("%d ",now );
		sum+=b[i],now+=sum;
		if(now<x){
			add-=(x-now);
			if(add<0) return 0;
			sum+=(x-now);
			b[min(i+2*R+1,n+1)]-=(x-now);
		}
	}
	return 1;
}

int main(){
	
	n=read(),R=read(),K=read();

	for(int i=1;i<=n;i++)
		c[i]=read(),s[i]=s[i-1]+c[i];

	ll l=0,r=s[n]+K,ans=0;
	while(l<=r){
		ll mid=(l+r)/2;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%lld\n",ans);
	return 0;
}