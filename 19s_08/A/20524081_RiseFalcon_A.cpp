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
	arr[4]=1;
	arr[8]=2;
	arr[15]=3;
	arr[16]=4;
	arr[23]=5;
	arr[42]=6;
	int N=input();
	for(int i=1;i<=N;++i) {
		a[i]=arr[input()];
	}
	for(int i=1;i<=N;++i) {
		if(a[i]==1) {
			tong[1]++;
		}else if(tong[a[i]-1]!=0){
			tong[a[i]-1]--;
			tong[a[i]]++;
		}
	}
	printf("%d\n",N-tong[6]*6);
	return 0;
}
