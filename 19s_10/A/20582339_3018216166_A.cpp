#include <bits/stdc++.h>
using namespace std;
char mp[1005][1005];
bool vis[1005][1005];
int h, w;
struct Node {
	int x, y, cnt;
	Node(){}
	Node(int xx, int yy, int cc):x(xx), y(yy), cnt(cc){}
};
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int main() {
	scanf("%d%d", &h, &w);
	for (int i = 1; i <= h; i++) scanf("%s", mp[i] + 1);
	memset(vis, false, sizeof(vis));
	queue<Node> que;
	int tot = h * w;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			if (mp[i][j] == '#') {
				que.push(Node(i, j, 0));
				vis[i][j] = true;
				tot--;
			}
		}
	}
	int ans = 0;
	while (!que.empty()) {
		Node t = que.front(); que.pop();
		if (!tot) break;
		for (int i = 0; i < 4; i++) {
			int tx = t.x + dx[i], ty = t.y + dy[i];
			if (tx < 1 || tx > h || ty < 1 || ty > w || vis[tx][ty]) continue;
			vis[tx][ty] = true;
			tot--;
			que.push(Node(tx, ty, t.cnt + 1));
			ans = max(ans, t.cnt + 1);
			if (!tot) break;
		}
	}
	printf("%d\n", ans);
	return 0;
}