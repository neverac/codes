#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define ll long long
using namespace std;

int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48,ch=getchar();}
	return x*f;
}
const int maxn = 50010;

int n,k;
struct Node{
	int w,d;
	bool operator < (const Node &x)const{
		return d>x.d;	
	}	
}a[maxn];
int c[maxn];
int check(int dis){
	memset(c,0,sizeof c);
	int ans=0;
	for(int i=1;i<=n;i++){
		int now=(dis-a[i].w*a[i].d)/a[i].w;
		if((dis-a[i].w*a[i].d)%a[i].w) now++;
		int l=1,r=n,p=0;
		while(l<=r){
			int mid=(l+r)/2;
			if(a[mid].d>=now) p=mid,l=mid+1;
			else r=mid-1;
		}		
		c[1]++,c[p+1]--;
		if(p>=i) c[i]--,c[i+1]++;
	}
	for(int i=1;i<=n;i++) c[i]+=c[i-1];
	for(int i=1;i<=n;i++) if(c[i]) ans++;
	//printf("%d %d\n",dis,ans);
	
	return ans;
}

int main(){
	
	int t=read();
	while(t--){
		n=read(),k=read();
		for(int i=1;i<=n;i++) a[i].w=read();
		for(int i=1;i<=n;i++) a[i].d=read();
		
		sort(a+1,a+n+1);
		
		int l=0,r=2e9,ans=0;
		
		while(l<=r){
			int mid=(l+r)/2;
			if(check(mid)<=n-k) r=mid-1;
			else l=mid+1;
		}
		printf("%d\n",r);		
	}
	return 0;
}
/*
2
3 2
5 3 4
3 8 5
4 2
6 2 8 2
10 18 12 4
*/