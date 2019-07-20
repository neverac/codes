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
const int maxn = 100010;
int L[maxn],R[maxn],W[maxn];
int num[maxn*4],c[maxn];
int s[maxn][32],le,ri;
#define lc rt<<1
#define rc rt<<1|1
void build(int rt,int l,int r){
	if(l==r){
		num[rt]=c[l];
		return;
	}
	int mid=(l+r)>>1;
	build(lc,l,mid);build(rc,mid+1,r);
	num[rt]=num[lc]&num[rc];
}

int query(int rt,int l,int r){
	if(le<=l&&ri>=r) return num[rt];
	int mid=(l+r)/2;
	if(ri<=mid) return query(lc,l,mid);
	else if(le>mid) return query(rc,mid+1,r);
	else return query(lc,l,mid)&query(rc,mid+1,r);
}

int main(){
	
	int n=read(),m=read();
	for(int i=1;i<=m;i++){
		L[i]=read(),R[i]=read(),W[i]=read();
		for(int j=0;j<30;j++){
			if((W[i]&(1<<j)))
				s[L[i]][j]++,s[R[i]+1][j]--;
		}
	}
	for(int j=0;j<30;j++)
		for(int i=1;i<=n;i++){
			s[i][j]+=s[i-1][j];
			if(s[i][j]) c[i]|=(1<<j);
 		}
	
	build(1,1,n);
	for(int i=1;i<=m;i++){
		le=L[i],ri=R[i];
		if(query(1,1,n)!=W[i]){
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	for(int i=1;i<=n;i++) printf("%d ",c[i]);
	
	return 0;
}
  