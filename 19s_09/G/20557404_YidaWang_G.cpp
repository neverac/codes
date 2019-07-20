#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

#define LL long long
#define INF 0x7fffffff
#define P 998244353

LL f[1000010];
inline void pre(){
	f[1]=1;
	f[2]=5;
	for (int i=3; i<=1000000; i++){
		f[i]=f[i-1]+i+1LL*i*(i-1)/2;
		if (i&1) f[i]+=1LL*(i/2)*(i/2+1);
		else f[i]+=1LL*(i/2)*(i/2+1)-(i/2); 
	}
}

int main(){
	int T; cin>>T;
	pre();
	while (T--){
		int n; cin>>n;
		printf("%lld\n",f[n]);
	}
	return 0;
}