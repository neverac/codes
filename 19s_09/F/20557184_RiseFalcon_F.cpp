#include <bits/stdc++.h>
typedef long long TYPE;
const TYPE mod=998244353;
const TYPE god=3;
const int MAXN=4E6+10;
const int INF=~0U>>1;
int input() {
	int x;scanf("%d",&x);
	return x;
}
TYPE pow(TYPE a,TYPE b) {
	TYPE ans=1;
	for(ans=1;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)ans=1ll*ans*a%mod;
	return ans;
}
void rotate(TYPE*a,int N) {
	for(int i=1,j=0;i<N;++i) {
		int k=N;
		do j^=(k>>=1); while(j<k);
		if(i<j)std::swap(a[i],a[j]);
	}
}
void NTT(TYPE *a,int N,int is) {
	rotate(a,N);
	for(int m=2;m<=N;m<<=1) {
		const int mh=m>>1;
		const TYPE wn=pow(god,is==1?mod-1-(mod-1)/m:(mod-1)/m);
		for(int r=0;r<N;r+=m) {
			TYPE w=1;
			TYPE*b=a+r;
			TYPE*c=a+r+mh;
			for(int k=0;k<mh;++k) {
				const TYPE u=b[k];
				const TYPE v=1ll*c[k]*w%mod;
				b[k]=(0ll+u+v)%mod;
				c[k]=(u-v+mod)%mod;
				w=1ll*w*wn%mod;
			}
		}
	}if(is<0) {
		const TYPE inv=pow(N,mod-2);
		for(int i=0;i<N;++i) {
			a[i]=1ll*a[i]*inv%mod;
		}
	}
}
void mulit(TYPE *a,TYPE*b,int N,int M) {
	for(int i=0;i<N*2;++i) {
		a[i]=1ll*a[i]*b[i]%mod;
	}
}
void pow2(TYPE *a,int N,int M){
	for(int i=0;i<N*2;++i) {
		a[i]=1ll*a[i]*a[i]%mod;
	}
}
TYPE ans[MAXN];
void pow(TYPE*a,int N,int b,int M) {
	ans[0]=1;
	NTT(a,N*2,1);
	NTT(ans,N*2,1);
	while(b) {
		if(b&1)mulit(ans,a,N,M);
		pow2(a,N,M);
		b>>=1;
	}
	NTT(ans,N*2,-1);
	for(int i=M;i<N*2;++i) {
		ans[i]=0;
	}
}
TYPE a[MAXN];
int main() {
	int N=input();
	int M=input();
	int W=N/2*10;
	int NN=1;
	while(NN<W)NN<<=1;
//	printf(">>> %d\n",NN);
	for(int i=1;i<=M;++i) {
		a[input()]=1;
	}
	pow(a,NN,N/2,W);
	TYPE cnt=0;
	for(int i=0;i<W;++i) {
		ans[i]=1ll*ans[i]*ans[i]%mod;
		cnt=(0ll+cnt+ans[i])%mod;
	} printf("%d\n",cnt);
	return 0;
}
