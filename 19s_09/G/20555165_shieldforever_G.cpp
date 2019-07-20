#include<iostream>
#include<cstdio>

using namespace std;

typedef long long LL;
#define N 1000001
LL a[N];
int n;
void solve(){
	LL i;
	a[1] = 1; a[2] = 5; a[3] = 13;
	for(i = 4; i <= N - 1; i++){
		a[i] = a[i - 1] + (i + 1) * i / 2LL;
		if(i % 2 == 1){
			a[i] += (i + 1LL) * (i - 1LL) / 4LL;
		}
		else{
			a[i] += i * i / 4LL;
		}
	}
	return ;
}

int main(){
	solve();
	int T;
	cin>>T;
	while(T--){
		scanf("%d", &n);
		printf("%lld\n", a[n]);
	}
	return 0;
}
