#include <cstdio>
#include <cstring>
#include <cstdlib>
//#include <algorithm>
typedef long long TYPE;
const int MAXN=1E5+10;
const int INF=~0U>>1;
const TYPE mod=1E9+7;
int input() {
	int x;scanf("%d",&x);
	return x;
}
int N,M;
struct FFF{
	TYPE w[MAXN<<2];
	TYPE z[MAXN<<2];
	int al,ar;
	TYPE x;
	TYPE ans;
	void update(int root,int l,int r) {
		w[root]=(w[root<<1]&w[root<<1|1]);
	}
	#define mid ((l+r)>>1)
	void push_down(int root,int l,int r) {
		if(z[root]==0)return;
		w[root<<1]=w[root<<1]|z[root];
		z[root<<1]=z[root<<1]|z[root];
		
		
		w[root<<1|1]=w[root<<1|1]|z[root];
		z[root<<1|1]=z[root<<1|1]|z[root];
		
		z[root]=0;
	}
	void change(int root,int l,int r) {
		if(ar<l || r<al)return;
		if(al<=l&&r<=ar) {
			
			z[root]=z[root]|x;
			
			w[root]=w[root]|x;
			return ;
		}
		push_down(root,l,r);
		if(al<=mid)change(root<<1,l,mid);
		if(ar> mid)change(root<<1|1,mid+1,r);
		update(root,l,r);
	}
	void query(int root,int l,int r) {
		if(ar<l || r<al)return;
		if(al<=l&&r<=ar) {
			ans=ans&w[root];
			return ;
		}
		push_down(root,l,r);
		if(al<=mid)query(root<<1,l,mid);
		if(ar> mid)query(root<<1|1,mid+1,r);
		update(root,l,r);
	}
	void Change(int l,int r,int zx) {
		x=zx;al=l;ar=r;
		change(1,1,N);
	}
	TYPE Query(int l,int r) {
		ans=INF;
		al=l;ar=r;
		query(1,1,N);
		return ans;
	}
}f;
int L[MAXN],R[MAXN],X[MAXN];
int main() {
	N=input();M=input();
	for(int i=1;i<=M;++i) {
		L[i]=input();
		R[i]=input();
		X[i]=input();
		f.Change(L[i],R[i],X[i]);
	}
	bool judge=true;
	for(int i=1;i<=M;++i) {
		if(f.Query(L[i],R[i])!=X[i])judge=false; 
	}
	printf(judge?"YES\n":"NO\n");
	if(judge) {
		for(int i=1;i<=N;++i) {
			printf("%d ",f.Query(i,i));
		}
	}
	return 0;
}
