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

const int maxn = 1010;
int c[maxn][maxn],b[maxn][maxn];
int s[maxn][maxn],n;
int h[maxn][maxn],l[maxn][maxn];
int sh[maxn][maxn],sl[maxn][maxn];

bool check(int k){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int ii=i+k-1,jj=j+k-1;
			int x=s[ii][jj]-s[i][jj]-s[ii][j]+s[i][j];
			int y=sh[ii][j]-sh[i][j]+sl[i][jj]-sl[i][j];
			if(x+y==k*k-1) return 1;
		}
	}return 0;
}
int main(){
	
	n=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			c[i][j]=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int flag=0;
			if(i-1==0||c[i-1][j]==c[i][j]-1) flag++;
			if(j-1==0||c[i][j-1]==c[i][j]-1) flag++;
			if(flag==2) b[i][j]=1;
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+b[i][j];
			if(c[i][j]==c[i-1][j]+1) h[i][j]=1;
			if(c[i][j]==c[i][j-1]+1) l[i][j]=1;
			sh[i][j]=sh[i-1][j]+h[i][j];
			sl[i][j]=sl[i][j-1]+l[i][j];
		}
	}

	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",ans );
	return 0;
}
  