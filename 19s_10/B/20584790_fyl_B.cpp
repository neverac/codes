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
const int maxn = 200010;
char S[maxn],T[maxn];
int U1[maxn],D1[maxn],L1[maxn],R1[maxn];
int U2[maxn],D2[maxn],L2[maxn],R2[maxn];
int main(){
	int n=read(),m=read(),K=read();
	int sx=read(),sy=read();
	scanf("%s",S+1);
	scanf("%s",T+1);
	for(int i=1;i<=K;i++){
		U1[i]=U1[i-1]+(S[i]=='U');
		U2[i]=U2[i-1]+(T[i]=='U');
		D1[i]=D1[i-1]+(S[i]=='D');
		D2[i]=D2[i-1]+(T[i]=='D');
		L1[i]=L1[i-1]+(S[i]=='L');
		L2[i]=L2[i-1]+(T[i]=='L');
		R1[i]=R1[i-1]+(S[i]=='R');
		R2[i]=R2[i-1]+(T[i]=='R');
	}
	bool flag=0;
	for(int i=1;i<=K;i++){
		if(sy-L1[i]+R2[i-1]<=0){flag=1;break;}
		if(sy+R1[i]-L2[i-1]>m){flag=1;break;}
		if(sx-U1[i]+D2[i-1]<=0){flag=1;break;}
		if(sx+D1[i]-U2[i-1]>n){flag=1;break;}
	}
	if(sy-L1[K]<=0){
		int nd=1-sy+L1[K];
		//printf("%d\n",nd);
		for(int i=K;i>=0;i--){
			if(R2[K]-R2[i]==nd){
				//printf("%d\n",i );
				for(int j=i+1;j<=K;j++)
					if(sy-L1[j]+(R2[j]-R2[i])>m){flag=1;break;}
				break;
			}
		}
	}
	if(sy+R1[K]>m){
		int nd=sy+R1[K]-m;
		for(int i=K;i>=0;i--){
			if(L2[K]-L2[i]==nd){
				for(int j=i+1;j<=K;j++)
					if(sy+R1[j]-(L2[j]-L2[i])<=0){flag=1;break;}
				break;
			}
		}
	}
	if(sx-U1[K]<=0){
		int nd=1-sx+U1[K];
		for(int i=K;i>=0;i--){
			if(D2[K]-D2[i]==nd){
				for(int j=i+1;j<=K;j++)
					if(sx-U1[j]+(D2[j]-D2[i])>n){flag=1;break;}
				break;
			}
		}
	}
	if(sx+D1[K]>n){
		int nd=sx+D1[K]-n;
		for(int i=K;i>=0;i--){
			if(U2[K]-U2[i]==nd){
				for(int j=i+1;j<=K;j++)
					if(sx+D1[j]-(U2[j]-U2[i])<=0){flag=1;break;}
				break;
			}
		}
	}
	if(flag) printf("NO\n");
	else printf("YES\n");
	return 0;
}
  