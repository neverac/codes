#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;

int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48,ch=getchar();}
	return x*f;
}

const int maxn = 100100;

int c[maxn],b[maxn],n,D;

bool check(int x){
	for(int i=1;i<=n;i++) b[i]=c[i];
	if(x==1) b[1]=b[2]+D;
	else if(x==n) b[n]=b[n-1]+D;
	
	else{
		if(abs(b[x+1]-b[x-1])<=2*D)
			b[x]=max(b[x+1],b[x-1])-D;
	}
	for(int i=2;i<n;i++)
		if(abs(b[i+1]-b[i])>D||abs(b[i-1]-b[i])>D) return 0;
	return 1;	
}

int main(){

	while(scanf("%d",&n)!=EOF&&n){
		D=read();
		
		for(int i=1;i<=n;i++) c[i]=read();
		
		//sort(c+1,c+n+1);
		
		if(n<=2){printf("Y\n");continue;}
		bool flag=0;
		for(int i=2;i<n;i++){
			if(abs(c[i]-c[i-1])<=D&&abs(c[i]-c[i+1])<=D) continue;
			flag=1;break;
		}
		
		
		for(int i=1;i<=n;i++) if(check(i)){flag=0;break;}
		
		if(!flag){printf("Y\n");continue;}
		else printf("N\n");
	}	
	
	return 0;
}
/*
3 2 
2 4 6
3 1
3 5 7
0
*/