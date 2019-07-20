#include <bits/stdc++.h>
typedef long long TYPE;
const TYPE mod=1E9+7;
const int MAXN=5E5+10;
const int INF=~0U>>1;
int input() {
	int x;scanf("%d",&x);
	return x;
}
int arr[100],tong[10],a[MAXN];
int main() {
	TYPE K,A,B;
	K=input();
	A=input();
	B=input();
	if(B-A>2) {
		if(A-1 >=K) {
			printf("%lld\n",K+1);
		}else {
			K-=(A-1);
			TYPE ans=0;
			ans=A+(K/2)*(B-A);
			K-=TYPE(K/2)*2;
			printf("%lld\n",ans+K);
		}
	}else {
		printf("%lld\n",K+1);
	}
	return 0;
}
