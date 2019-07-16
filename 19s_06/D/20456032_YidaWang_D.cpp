#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <vector>

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

int main(){
	int x=read(),y=read(),z=read();
	int a=read(),b=read(),c=read();
	a-=x;
	if (a<0){
		puts("NO");
		return 0;
	}
	if (a+b<y){
		puts("NO");
		return 0;
	}
	if (a+b-y+c-z<0){
		puts("NO");
		return 0;
	}
	puts("YES");
	return 0;
}