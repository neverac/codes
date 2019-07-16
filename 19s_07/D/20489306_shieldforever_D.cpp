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
char s[N];
int f1[N], f2[N], f[N];
int n;

void solve(){
	int i,j,k;
	scanf("%s", s + 1);
	n = strlen(s + 1);
	f1[0] = 0;
	for(i = 1; i <= n; i++){
		if(s[i] == '0') f1[i] = f1[i - 1];
		else f1[i] = f1[i - 1] + 1;
	}
	f2[n + 1] = 0;
	for(i = n; i >= 1; i--){
		if(s[i] == '1') f2[i] = f2[i + 1];
		else f2[i] = f2[i + 1] + 1;
	}
	int ans = 2000;
	for(i = 0; i <= n; i++){
		f[i] = f1[i] + f2[i + 1];
		if(ans > f[i]) ans = f[i];
	}
	printf("%d\n", ans);
}

int main(){
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
