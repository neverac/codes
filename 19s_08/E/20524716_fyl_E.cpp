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
int c[1010],num[5];
int main(){
	int t=read();
	while(t--){
		memset(num,0,sizeof num);
		int n=read();
		for(int i=1;i<=n;i++){
			c[i]=read()%3;
			num[c[i]]++;
		}
		int ans=num[0],k=min(num[1],num[2]);
		printf("%d\n",ans+k+(max(num[1],num[2])-k)/3);
	}
	return 0;
}
  