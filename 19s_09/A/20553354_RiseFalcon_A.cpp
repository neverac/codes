#include <bits/stdc++.h>
typedef long long TYPE;
const TYPE mod=1E9+7;
const int MAXN=1E5+10;
const int INF=~0U>>1;
int input() {
	int x;scanf("%d",&x);
	return x;
}
struct path {
	int to,next,dis;
	path(int a=0,int b=0,int c=0){
		to=a;next=b;dis=c;
	} 
}; 
int main() {
	int T=input();
	while(T-->0) {
		int x=input();
		int r=input();
		printf("%d %d\n",x,2*x);
	}
	return 0;
}
