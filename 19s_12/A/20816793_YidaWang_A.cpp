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
int visit[10];
int main(){
	int P=read(),Q=read();
	P*=10;
	for (int i=1; i<=1000000; i++){
		int t = P/Q;
		P%=Q;
		if (!visit[t]) visit[t]=1;
		P*=10;
		if (P==0) break;
	}
	for (int i=0; i<=9; i++) if (visit[i]) printf("%d",i);
	return 0;
}

/*
13 123
*/
	