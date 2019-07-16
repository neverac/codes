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
int main(){
	
	int x=read(),y=read(),z=read();

	int a=read(),b=read(),c=read();

	if(a<x){printf("NO\n");return 0;}
	a-=x;
	if(a+b<y){printf("NO\n");return 0;}
	if(a>=y) a-=y;
	else y-=a,a=0,b-=y;
	if(a+b+c<z){printf("NO\n");return 0;}
	printf("YES\n");
	return 0;
}
  