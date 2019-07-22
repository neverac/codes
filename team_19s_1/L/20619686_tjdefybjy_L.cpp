#include <bits/stdc++.h>
typedef long long TYPE;
const TYPE mod=1E9+7;
const int MAXN=1E5+10;
const int INF=~0U>>1;
const int ud[4]={0,1,0,-1};
const int lr[4]={1,0,-1,0};
int input() {
	int x;scanf("%d",&x);
	return x;
}
struct node {
	int x,y;
	node (int a=0,int b=0) {
		x=a;y=b;
	}
}w[MAXN];
bool operator < (const node&a,const node&b) {
	return a.x<b.x;
}
int doing() {
	int N=input();
	for(int i=1;i<=N;++i) {
		w[i]=node(input(),i);
	}
	printf("%d\n",int(sqrt(std::abs(w[1].x-w[N].x))));
	return 0;
}
int main() {
	int T=input();
	while(T-->0)doing();
	return 0;
}
