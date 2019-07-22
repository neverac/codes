#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48,ch=getchar();}
	return x*f;
}

const int mod = 1000000007;
const int inv2 = 500000004;
const int maxn = 100010;

int fac[maxn],inv[maxn];
int qk_pow(int a,int b){
	int p=1;
	for(int i=b;i;i>>=1,a=1ll*a*a%mod)
		if(i&1) p=1ll*p*a%mod;
	return p;
}
int C(int m,int n){
	if(m>n) return 0;
	return 1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int block[maxn],Ans[maxn];
struct que{
	int n,m,op;
	bool operator < (const que &a)const{
		if(block[m]==block[a.m]) return n<a.n;
		return m<a.m;
	}
}q[maxn];

int main(){
	//printf("%d\n",qk_pow(2,mod-2));
	fac[0]=1;
	for(int i=1;i<=100000;i++) fac[i]=1ll*fac[i-1]*i%mod;
	inv[100000]=qk_pow(fac[100000],mod-2);
	for(int i=99999;i>=0;i--) inv[i]=1ll*inv[i+1]*(i+1)%mod;
	int size=sqrt(100000);
	for(int i=1;i<=100000;i++) block[i]=i/size+1;
	int t=read();
	for(int i=1;i<=t;i++)
		q[i].n=read(),q[i].m=read(),q[i].op=i;
	sort(q+1,q+t+1);
	
	int n=1,m=0,ans=1;
	for(int i=1;i<=t;i++){
		while(n<q[i].n) ans=(ans*2ll%mod-C(m,n)+mod)%mod,n++;
		while(m<q[i].m) ans=(ans+C(m+1,n))%mod,m++;
		while(m>q[i].m) ans=((ans-C(m,n))%mod+mod)%mod,m--;
		while(n>q[i].n) ans=1ll*(ans+C(m,n-1))%mod*inv2%mod,n--;
		Ans[q[i].op]=ans;
	}
	for(int i=1;i<=t;i++)
		printf("%d\n",Ans[i]);
	return 0;
}
/*
123
*/