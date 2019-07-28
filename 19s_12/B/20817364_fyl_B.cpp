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
const int maxn = 1001000;
char s[maxn];
int p[maxn];
void manacher(){
	int n=strlen(s+1)<<1|1;
	for(int i=n;i;i--)
		if(i&1) s[i]='#';
		else s[i]=s[i>>1];
	s[0]='$';
	int mx=0,id=0;
	for(int i=1;i<=n;i++){
		p[i]=i<mx?min(mx-i,p[id*2-i]):1;
		while(s[i+p[i]]==s[i-p[i]]) p[i]++;
		if(i+p[i]>mx) mx=i+p[i],id=i;
	}
	
}
bool check(int l,int r){
	//printf("%d %d\n",l,r);
	
	l*=2,r*=2;
	int mid=(l+r)/2;
	return p[mid]>=r-mid+1;
}

int main(){
	
	scanf("%s",s+1);
	
	
	int n=strlen(s+1),mx=1;
	while(mx<=n/2&&s[mx]==s[n-mx+1]){
		//printf("%d %c %c\n",mx,s[mx],s[n-mx+1]);
		mx++;
	}
	//printf("%d\n",mx);
	manacher();
	//printf("%s\n",s);
	
	for(int i=1;i<=mx;i++){
		if(check(i+1,n-(i-1))){
			printf("%d\n",i);break;
		}
	}
	
	return 0;
}

/*
aacbbaa
*/