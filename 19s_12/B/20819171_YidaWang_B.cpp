#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

#define LL long long
#define ULL unsigned long long
#define INF 0x7fffffff

LL read(){
	LL x=0,f=1; char ch=getchar();
	while (ch<'0' || ch>'9') {if (ch=='-') f=-1; ch=getchar();}
	while (ch>='0' && ch<='9') {x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}

#define Pa pair<int,int>
#define MP make_pair

#define ULL unsigned long long
#define BASE 23
#define MOD 1000000007

ULL H[2][500010]={0},bin[500010];
char s[500010];
int n;
ULL GetHash(int l,int r,int opt)
{
	if (l>r) return 0;
    return (H[opt][r]-H[opt][l-1]*bin[r-l+1]%MOD+MOD)%MOD;
}

int visit[10];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for (int i=1; i<=n; i++) H[0][i]=(H[0][i-1]*BASE+s[i])%MOD;
	for (int i=1; i<=n/2; i++) swap(s[i],s[n-i+1]);
	//puts(s+1);
	for (int i=1; i<=n; i++) H[1][i]=(H[1][i-1]*BASE+s[i])%MOD;
	
	
	bin[0]=1;
	for (int i=1; i<=n; i++) bin[i]=bin[i-1]*BASE%MOD;
//	printf("%llu %llu %llu %llu %llu %llu %llu\n",H[0][3],GetHash(2,3,0),GetHash(1,1,0),H[0][1],bin[2],GetHash(1,1,0)*bin[2]+GetHash(2,3,0),H[0][1]*bin[2]+GetHash(2,3,0));
	int len = (n-1)/2;
	for (int i=1; i<=n; i++){
		ULL hr,hl;
		if (n-i>=len){
		//	hr=GetHash(n-len+1,n),
			hr=GetHash(1,len,1);
			hl=(bin[i+1+len-(i-1)-1-(i+1)+1]*GetHash(1,i-1,0)%MOD+GetHash(i+1,i+1+len-(i-1)-1,0)%MOD)%MOD;
//			printf("fuck1 %d\n",i);
		//	printf("%d %d %d %d %d %d\n",n-len+1,n,1,i-1,i+1,i+1+len-(i-1)-1);
			}
		else {
			hl=GetHash(n-len+1,n,1),
			hr=(GetHash((i-1)-(len-(n-i))+1,i-1,0)*bin[n-i]%MOD+GetHash(i+1,n,0)%MOD)%MOD;
//			printf("fuck2 %d\n",i);
		//	printf("%d %d %d %d %d %d\n",1,len,(i-1)-(len-(n-i))+1,i-1,i+1,n);
			}
//		printf("debug %llu %llu\n",hl,hr);
		if (hr==hl){
			printf("%d\n",i);
			break;
		}
	}
	return 0;
}

/*
baa
aaaaa
aaba
aabbcaa
*/
	