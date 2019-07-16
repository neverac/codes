#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <vector>

using namespace std;
#define LL long long
#define INF 0x7fffffff
#define P 998244353

inline LL read(){
    LL x=0,f=1; char ch=getchar();
    while (ch<'0' || ch>'9') {if (ch=='-') f=-1; ch=getchar();}
    while (ch>='0' && ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}

int a[200],f[200][200],sum[200],n;

int main(){
	while (scanf("%d",&n)!=EOF){
		for (int i=1; i<=n; i++) a[i]=read(),a[i]%=100;
		for (int i=1; i<=n; i++) sum[i]=(sum[i-1]+a[i])%100;

		// for (int i=1; i<=n; i++) printf("%d  ",sum[i]); puts("");
		for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) f[i][j]=INF;
		for (int i=1; i<=n; i++) f[i][i]=0;
		for (int i=1; i<=n-1; i++) f[i][i+1]=a[i]*a[i+1];
			
		for (int len=3; len<=n; len++){
			for (int l=1,r=l+len-1; r<=n; l++,r++){
				for (int k=l; k<r; k++){
					int t = ((sum[k]-sum[l-1]+100)%100) * ((sum[r]-sum[k]+100)%100);
					// printf("debugl-k %d %d %d %d\n",l,k,f[l][k],(sum[k]-sum[l-1]+100)%100);
					// printf("debugk+1-r %d %d %d %d\n",k+1,r,f[k+1][r],(sum[r]-sum[k]+100)%100);
					f[l][r]=min(f[l][r],f[l][k]+f[k+1][r]+t);
				}
			}
		}
		printf("%d\n",f[1][n]);
	}
	return 0;
}