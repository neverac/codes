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
const int maxn = 510;
int N;
struct Number{
	int a[maxn],len;
	Number(){memset(a,0,sizeof a);len=0;}
	void Set(){
		//printf("1\n");
		len++;
		for(int i=1;i<=len;i++)
			a[i+1]+=a[i]/N,a[i]%=N;
		while(a[len]==0&&len>0)len--;
	}
	void operator +=(const Number &x){
		len=max(len,x.len);
		for(int i=1;i<=len;i++) a[i]+=x.a[i];
		Set();
	}
	void operator =(const Number &x){
		memset(a,0,sizeof(a));
		len=x.len;
		memcpy(a,x.a,sizeof(x.a));
	}
	void Print(){
		if(len==0) printf("0");
		for(int i=len;i>=1;i--) printf("%d",a[i]);
	}
}C[310][310];

Number operator +(const Number &A,const Number &B){
	Number x;
	x+=A;x+=B;x.Set();
	return x;
}

int main(){
	
	int t=read(),n,k;
	while(t--){
		n=read(),k=read(),N=read();
		for(int i=0;i<=n;i++)
			C[i][0].len=1,C[i][0].a[1]=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=min(i,k);j++)
				C[i][j]=C[i-1][j-1]+C[i-1][j];
		C[n][k].Print();puts("");
	}	
	return 0;
}
/*
1
300 150 2
*/