#include <bits/stdc++.h>
typedef long long TYPE;
const TYPE mod=1E9+7;
const int MAXN=1E5+10;
const int INF=~0U>>1;
int sqr=sqrt(MAXN);
int input() {
	int x;scanf("%d",&x);
	return x;
}
struct pair {
	int l,r,id;
	pair(int a=0,int b=0,int c=0) {
		l=a,r=b,id=c;
	} 
}w[MAXN];
bool operator < (const pair&a,const pair&b) {
	if(a.r/sqr!=b.r/sqr) return a.r/sqr < b.r/sqr;
	return a.l<b.l;
}
TYPE pow(TYPE a,TYPE b) {
	TYPE ans=1;
	while(b) {
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;b>>=1;
	}
	return ans;
}
const TYPE inv2=pow(2,mod-2);
TYPE js[MAXN],ij[MAXN];
void setup (int N) {
	js[0]=1;
	for(int i=1;i<=N;++i)js[i]=js[i-1]*i%mod;
	ij[N]=pow(js[N],mod-2);
	for(int i=N-1;i>=0;--i)ij[i]=ij[i+1]*(i+1)%mod;
}
TYPE C(int n,int m) {
	if(0<=m &&m<=n)return js[n]*ij[m]%mod*ij[n-m]%mod;
	else return 0;
}
TYPE ans,answer[MAXN];
void decM(int n,int m) {
	ans-=C(n,m);ans+=mod;ans%=mod;

}
void incM(int n,int m) {
	ans+=C(n,m);ans%=mod;
}
void decN(int n,int m) {
	ans=(ans+C(n-1,m))%mod*inv2%mod;
}
void incN(int n,int m) {
	ans=(2*ans%mod+mod-C(n,m))%mod;
}
int main() {
	setup(1E5);
	int T=input();
	for(int i=1;i<=T;++i) {
		w[i].r=input();
		w[i].l=input();
		w[i].id=i;
	}
	std::sort(w+1,w+T+1);
	int l=0,r=0;ans=1;
	for(int i=1;i<=T;++i) {
		while(r<w[i].r)incN(r++,l);
		while(r>w[i].r)decN(r--,l);
		while(l<w[i].l)incM(r,++l);
		while(l>w[i].l)decM(r,l--);
		answer[w[i].id]=ans;
	}
	for(int i=1;i<=T;++i) {
		printf("%lld\n",answer[i]);
	}
	return 0;
}
