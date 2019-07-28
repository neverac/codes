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

const int maxn = 100100;

int c[maxn],p[maxn][3];
ll F[maxn];
int main(){
	int n=read();
	for(int i=1,x;i<=n*2;i++){
		x=read();
		p[x][++p[x][0]]=i;
	}
	
	F[1]=p[1][1]+p[1][2]-2;
//	printf("%d\n",F[1]);
	
	for(int i=2;i<=n;i++){
		int a=p[i][1],b=p[i][2];
		F[i]=F[i-1]+abs(p[i-1][1]-a)+abs(p[i-1][2]-b);
		F[i]=min(F[i],F[i-1]+abs(p[i-1][2]-a)+abs(p[i-1][1]-b));	
		//printf("%d\n",F[i]);
		
	}	
	printf("%lld\n",F[n]);
	
	return 0;
	
}
/*
3
1 1 2 2 3 3
4
4 1 3 2 2 3 1 4
*/