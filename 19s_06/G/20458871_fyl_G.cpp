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

const int maxn = 110;
int c[maxn],f[maxn][maxn],s[maxn][maxn];

int main(){
	int n;
	
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;i++) c[i]=read();

		for(int i=1;i<=n;i++){
			s[i][i]=c[i];
			for(int j=i+1;j<=n;j++)
				s[i][j]=(s[i][j-1]+c[j])%100;
		}

		memset(f,0x3f,sizeof f);
		for(int i=1;i<=n;i++) f[i][i]=0;
		for(int i=1;i<n;i++)
			f[i][i+1]=c[i]*c[i+1];
		for(int l=3;l<=n;l++){
			for(int i=1;i+l-1<=n;i++){
				int j=i+l-1;
				for(int k=i;k<j;k++){
					f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+s[i][k]*s[k+1][j]);
				}
			}
		}

		printf("%d\n",f[1][n]);
	}
	return 0;
}
  