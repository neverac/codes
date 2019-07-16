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

#define N 110
#define inf 0x3f3f3f3f
int a[N], f[N][N], s[N];
int n;

void init(){
	int i,j,k;
	s[0] = 0;
	for(i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		f[i][i] = 0;
		s[i] = s[i - 1] + a[i];
	}
	return ;
}

void solve(){
	int i,j,k,p;
	for(k = 1; k <= n - 1; k++){
		for(i = 1; i + k <= n; i++){
			j = i + k;
			f[i][j] = inf;
			for(p = i; p < j; p++){
				int s1 = (s[p] - s[i - 1]) % 100;
				int s2 = (s[j] - s[p]) % 100;
				f[i][j] = min(f[i][j], f[i][p] + f[p + 1][j] + s1 * s2);
			}
		}
	}
	printf("%d\n", f[1][n]);
}

int main(){
	while(~scanf("%d", &n)){
		init();
		solve();
	}
	return 0;
}
