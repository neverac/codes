#include <bits/stdc++.h>
#define debug(x) cout << x << endl
using namespace std;
int n;
int a[1005][1005];
int ans;
void dfs(int x, int y) {
	int cnt = 1;
	int tx = x, ty = y;
	while (tx < n && ty < n) {
		if (a[tx + 1][ty + 1] == a[tx][ty] + 2) {
			cnt++; tx++; ty++;
		}
		else {
			break;
		}
	}
	if (cnt < ans) return;
	int t = 1;
	while (t <= cnt) {
		bool f = false;
		if ((a[x][y + t] != (a[x][y + t - 1] + 1)) || (a[x + t][y] != (a[x + t - 1][y] + 1))) break;
		for (int i = x + 1; i <= x + t; i++) {
			if (a[i][y + t] != (a[i - 1][y + t] + 1)) {
				f = true; break;
			}
		}
		if (f) break;
		for (int i = y + 1; i <= y + t; i++) {
			if (a[x + t][i] != (a[x + t][i - 1] + 1)) {
				f = true; break;
			}
		}
		if (f) break;
		t++;
	}
	ans = max(t, ans);
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dfs(i, j);
		}
	}
	printf("%d\n", ans);
	return 0;
}