#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
#define ll long long 
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48,ch=getchar();}
	return x*f;
}

int c[201000],b[200100],p[201000];
bool cmp(int x,int y){
	return c[x]>c[y];
}

int main(){
	
	int n=read(),m=read(),k=read();

	for(int i=1;i<=n;i++)
		c[i]=read(),b[i]=i;
	sort(b+1,b+n+1,cmp);

	ll ans=0;
	for(int i=1;i<=m*k;i++)
		ans+=c[b[i]],p[i]=b[i];
	printf("%lld\n",ans);
	sort(p+1,p+m*k+1);
	// for(int i=1;i<=m*k;i++)
	// 	printf("%d\n",p[i] );
	for(int i=1;i<k;i++)
		printf("%d ",p[i*m]);
	return 0;
}
  