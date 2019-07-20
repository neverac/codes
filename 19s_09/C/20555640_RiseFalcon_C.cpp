#include <bits/stdc++.h>
typedef long long TYPE;
const TYPE mod=1E9+7;
const int MAXN=1E5+10;
const int INF=~0U>>1;
int input() {
	int x;scanf("%d",&x);
	return x;
}
int find(int d) {
	for(int n=3;n<=360;++n) {
		double rx=360.0/n;
		if(d<90) {
			double rd=d< 90 ? (d*2):(180-d)*2;
			if(fmod(rd,rx)<1E-6 && rd/rx>1-1E-8) {
				return n;
			}
		} else {
			double rd=d< 90 ? (d*2):(180-d)*2;
			if(fmod(rd,rx)<1E-6 && rd/rx>2-1E-8) {
				return n;
			}
		}
	}return -1;
}
int main() {
	int T=input();
	for(int i=1;i<=T;++i) {
		printf("%d\n",find(input()));
	}
	return 0;
}
