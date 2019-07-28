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
int v[10];
bool mp[10000100];
int main(){
	int p=read(),q=read();
	
	p*=10;
	while(!mp[p]){
		mp[p]=1;
		v[p/q]=1;
		p%=q;
		if(p==0) break;
		p*=10;
	}
	for(int i=0;i<=9;i++)
		if(v[i]) printf("%d",i);
	return 0;
}
/*
1 7
*/