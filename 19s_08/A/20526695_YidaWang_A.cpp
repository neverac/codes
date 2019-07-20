#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <cstdlib>

using namespace std;

#define LL long long
#define INF 0x7fffffff
#define P 998244353

inline LL read(){
    LL x=0,f=1; char ch=getchar();
    while (ch<'0' || ch>'9') {if (ch=='-') f=-1; ch=getchar();}
    while (ch>='0' && ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}

int n;
int a[500010];
int id[50],num[10];

int main(){
	n=read();
	id[4]=1;
	id[8]=2;
	id[15]=3;
	id[16]=4;
	id[23]=5;
	id[42]=6;

	for (int i=1; i<=n; i++) a[i]=read();

	for (int i=1; i<=n; i++){
		if (num[ id[a[i]]-1 ] || id[a[i]]==1){
			num[id[a[i]]]++;
			num[id[a[i]]-1]--;
		}
	}
	printf("%d\n",n-6*num[6]);

	// for (int i=1; i<=n; i++){
	// 	if (num[ id[a[i]]-1 ]>num[ id[a[i]] ] || id[a[i]]==1){
	// 		num[id[a[i]]]++;
	// 	}
	// }
	// printf("%d\n",n-6*num[6]);
	return 0;
}