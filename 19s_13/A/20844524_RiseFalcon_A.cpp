#include <bits/stdc++.h>
typedef long long TYPE;
const TYPE mod=1E9+7;
const int MAXN=1E5+10;
const int INF=~0U>>1;
int input() {
	int x;scanf("%d",&x);
	return x;
}
int main() {
	int N=input();
	int c1=0,c11=0;
	for(int i=1;i<=N;++i) {
		int x=input();
		if(x>0)c1++;
		if(x<0)c11++;
	}
	int M=ceil(N/2.0);
	if(c1>=M)printf("1");
	else if(c11>=M)printf("-1");
	else printf("0");
	return 0;
}
