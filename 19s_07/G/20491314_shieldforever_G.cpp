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

#define N 1010
int a[N][N], b[N][N];
int f[N][N];
int n, ans;

void init(){
	int i,j,k;
	scanf("%d", &n);
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			scanf("%d", &a[i][j]);
		}
	}
	for(i = 1; i <= n; i++) b[i][1] = b[1][i] = 1;	
	for(i = 2; i <= n; i++){
		for(j = 2; j <= n; j++){
			if(a[i][j] - a[i - 1][j] == 1 && a[i][j] - a[i][j - 1] == 1){
				b[i][j] = 1;
			}
			else b[i][j] = 0;
		}
	}
}

void solve(){
	int i,j,k;
	ans = -1;
	for(i = 1; i <= n; i++) f[i][1] = 0;
	for(j = 1; j <= n; j++) f[1][j] = 0;
	for(i = 2; i <= n; i++){
		for(j = 2; j <= n; j++){
			if(b[i][j] == 0) continue;
			f[i][j] = min(f[i - 1][j], min(f[i][j - 1], f[i - 1][j - 1])) + 1;
			ans = max(ans, f[i][j]);
		}
	}
	printf("%d\n", ans + 1);
	return ;
}

int main(){
	init();
	solve();
	return 0;
}
