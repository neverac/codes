#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long TYPE;
const int MAXN=1E2+10;
const TYPE mod=1E9+7;
struct pir{
	int x,i;
	pir(int a=0,int b=0) {
		x=a;i=b;
	}
}w[MAXN];
bool operator < (const pir&a,const pir&b) {
	return a.x>b.x;
}
int f[MAXN][MAXN];
int a[MAXN];
int sum(int i,int j) {
	return (a[i]-a[j-1])%100;
}
int main() {
	int N;
	if(scanf("%d",&N)!=1)return 0;
	for(int i=1;i<=N;++i) {
		scanf("%d",&a[i]);
		a[i]+=a[i-1];
	}
	memset(f,63,sizeof f);
	for(int i=1;i<=N;++i) {
		f[i][i]=0;
		for(int j=i-1;j>=1;--j) {
			for(int k=j;k<i;++k) {
				f[i][j]=std::min(f[i][j],f[i][k+1]+f[k][j]+sum(i,k+1)*sum(k,j));
			}
		}
	}
//	for(int i=1;i<=N;++i) {
//		for(int j=1;j<=N;++j) {
//			printf("%d ",f[i][j]);
//		}printf("\n");
//	}
	printf("%d\n",f[N][1]);
	return main();
}