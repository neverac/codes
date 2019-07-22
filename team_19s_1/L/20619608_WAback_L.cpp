#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48,ch=getchar();}
	return x*f;
}
int c[1001000];
int main(){
	int t=read();
	while(t--){
		int n=read();
		for(int i=1;i<=n;i++) c[i]=read();
		//printf("%d %d %d\n",c[1],c[n],abs(c[1]-c[n]));
		if(c[n]<c[1]) swap(c[n],c[1]);
		printf("%d\n",(int)sqrt(1ll*c[n]-c[1]));
	}
	return 0;
}
/*
123
*/