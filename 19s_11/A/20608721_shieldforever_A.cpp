#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<string>
#include<iomanip>
#include<queue>

using namespace std;

#define N 100010
int d[N];
int n;

int main(){
	int i,j,k;
	cin>>n;
	for(i = 1; i <= n; i++)scanf("%d", &d[i]);
	sort(d + 1, d + 1 + n);
	long long m = 0, ans = 0;
	for(i = 1; i <= n; i++){
		ans += m * d[i];
		m += d[i];
		ans += m * d[i];
	}
	printf("%lld\n", ans);
	return 0;
}
