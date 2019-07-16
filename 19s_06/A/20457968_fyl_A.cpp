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
const int maxn = 2001000;
ll a[maxn],b[maxn],c[maxn],cnt;
void fac(ll n){
	for(ll i=2;i*i<=n;i++){
		if(n%i==0){
			a[++cnt]=i;
			while(n%i==0) b[cnt]++,n/=i;
		}
	}
	if(n!=1) a[++cnt]=n,b[cnt]++;
}
ll get(ll n,ll x){
	ll a=x,s=0;
	while(n/a){

		s+=n/a;
		if(n/a<x) break;
		a=a*x;
	}
	return s;
}
int main(){
	
	ll n=read(),B=read();
	
	fac(B);
	ll ans=0x7f7f7f7f7f7f7f7f;
	for(int i=1;i<=cnt;i++){
		ans=min(ans,get(n,a[i])/b[i]);
	}

	printf("%lld\n",ans);
	return 0;
}
  