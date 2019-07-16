#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;
#define ll long long 
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48,ch=getchar();}
	return x*f;
}

const int maxn = 400100;
const int mod = 1000000007;
int prim[100],tot,inv[100];
bool vis[310];
void get_prim(){
	for(int i=2;i<=300;i++){
		if(!vis[i]) prim[++tot]=i;
		for(int j=1;j<=tot&&i*prim[j]<=300;j++){
			vis[i*prim[j]]=1;
			if(i%prim[j]==0)break;
		}
	}
}

int qk_pow(int a,int b){
	int p=1;
	for(int i=b;i;i>>=1,a=1ll*a*a%mod)
		if(i&1) p=1ll*a*p%mod;
	return p;
}

#define lc rt<<1
#define rc rt<<1|1
int c[maxn],le,ri;
ll lazy[maxn*4],lazys[maxn*4];

struct Node{
	ll num,sta;
	Node(){num=0,sta=0;}
	Node operator + (const Node &a)const{
		Node c;
		c.num = num*a.num%mod;
		c.sta = sta|a.sta;
		return c;
	}
}tr[maxn*4];


void build(int rt,int l,int r){
	lazy[rt]=1;
	if(l==r){
		tr[rt].num=c[l];
		for(int i=1;i<=tot;i++)
			if(c[l]%prim[i]==0)
				tr[rt].sta|=(1LL<<(i-1));
		return;
	}
	int mid=(l+r)>>1;
	build(lc,l,mid);build(rc,mid+1,r);
	tr[rt] = tr[lc] + tr[rc];
}

void push_down(int rt,int l,int r){
	if(lazy[rt]==1) return;
	int mid=(l+r)>>1;
	tr[lc].num=tr[lc].num*qk_pow(lazy[rt],mid-l+1)%mod;
	tr[rc].num=tr[rc].num*qk_pow(lazy[rt],r-mid)%mod;

	tr[lc].sta|=lazys[rt];
	tr[rc].sta|=lazys[rt];

	lazy[lc]=lazy[lc]*lazy[rt]%mod;
	lazy[rc]=lazy[rc]*lazy[rt]%mod;

	lazys[lc]|=lazys[rt];
	lazys[rc]|=lazys[rt];

	lazy[rt]=1;
}

void modify(int rt,int l,int r,int x,ll S){
	if(le<=l&&ri>=r){
		tr[rt].num=tr[rt].num*qk_pow(x,r-l+1)%mod;
		tr[rt].sta |= S;
		lazy[rt]=lazy[rt]*x%mod;
		lazys[rt] |= S;
		return;
	}
	push_down(rt,l,r);
	int mid=(l+r)>>1;
	if(le<=mid) modify(lc,l,mid,x,S);
	if(ri>mid) modify(rc,mid+1,r,x,S);
	tr[rt] = tr[lc] + tr[rc];
}
Node query(int rt,int l,int r){
	if(le<=l&&ri>=r) return tr[rt];
	push_down(rt,l,r);
	int mid=(l+r)>>1;
	if(ri<=mid) return query(lc,l,mid);
	else if(le>mid) return query(rc,mid+1,r);
	else return query(lc,l,mid)+query(rc,mid+1,r);
}

int main(){
	
	get_prim();
	for(int i=1;i<=tot;i++)
		inv[i]=qk_pow(prim[i],mod-2);

	int n=read(),m=read();
	for(int i=1;i<=n;i++) c[i]=read();

	build(1,1,n);
	char ch[10];
	for(int i=1;i<=m;i++){
		scanf("%s",ch);
		le=read(),ri=read();
		if(ch[0]=='T'){
			Node x=query(1,1,n);
			ll ans=x.num;
			for(int i=1;i<=tot;i++)
				if(x.sta&(1LL<<(i-1)))
					ans=ans*inv[i]%mod*(prim[i]-1)%mod;
			printf("%lld\n",ans);
		}
		else{
			int x=read();ll S=0;
			for(int i=1;i<=tot;i++)
				if(x%prim[i]==0) S|=(1LL<<(i-1));
			modify(1,1,n,x,S);
		}
	}
	return 0;
}
