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

#define N 500050
int a[N];
int b[N] = {0, 4, 8, 15, 16, 23, 42};
int t[7];
int n, ans;

void solve(){
	int i,j,k;
	ans = 0;
	t[0] = 0x3f3f3f3f;
	for(i = 1; i <= n; i++){
		for(j = 1; j <= 6; j++){
			if(a[i] == b[j]){
				if(t[j] < t[j - 1])t[j]++;
			}
		}
//		int now = j;
//		for(k = 1; k < now; k++){
//			if(t[k] < t[now] + 1)
//		}
	}
	ans = n - t[6] * 6;
	printf("%d\n", ans);
}

int main(){
	int i,j,k;
	cin>>n;
	for(i = 1; i <= n; i++)scanf("%d", &a[i]);
	solve();
	return 0;
}
