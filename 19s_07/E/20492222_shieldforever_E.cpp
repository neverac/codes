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
char s[N];
int t[27];
int ans[N];
int n;

void solve(){
	int i,j,k;
	n = strlen(s + 1);
	for(i = 1; i <= n; i++){
		t[s[i] - 'a' + 1]++;
	}
}

int dfs(int now){
	int i,j,k;
	if(now == n + 1) return true;
	for(i = 1; i <= 26; i++){
		if(t[i] > (n - now + 2) / 2) return false;
	}
	for(i = 1; i <= 26; i++){
		if(ans[now - 1] != i && t[i] > 0){
			t[i]--;
			ans[now] = i;
			if(dfs(now + 1)) return 1;
			t[i]++;
 		}
	}
	return 0;
}

int main(){
	scanf("%s", s + 1);
	solve();
	ans[0] = -1;
	if(dfs(1)){
		for(int i = 1; i <= n; i++)printf("%c", ans[i] + 'a' - 1);
	}
	else printf("INVALID\n");
	return 0;
}
