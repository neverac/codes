#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#define ll long long
using namespace std;

int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48,ch=getchar();}
	return x*f;
}
const int maxn=310;
int c[maxn][maxn];
int main(){
	int t=read();
	while(t--){
		int n=read();
		for(int i=1;i<=n*(n-1)/2;i++){
			int x=read(),y=read(),z=read();
			if(x>y) swap(x,y);
			c[x][y]=z;		
		}
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					ans=max(ans,c[i][j]+c[i][k]+c[j][k]);
		printf("%d\n",ans);
	}
	
	return 0;
}
/*
2
3
1 2 1
1 3 1
2 3 1
4
1 2 2
1 3 2
1 4 1
2 3 2
2 4 1
3 4 1
*/