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


char s[10010];
int c[10100];
int main(){
	
	int t=read();

	while(t--){
		scanf("%s",s+1);
		int n=strlen(s+1);
		for(int i=1;i<=n;i++)
			c[i]=c[i-1]+(s[i]=='1');
		int ans=n;
		for(int i=0;i<=n;i++){
			ans=min(ans,c[i]+(n-i)-(c[n]-c[i]));
		}
		printf("%d\n",ans );
	}


	
	
	return 0;
}
  