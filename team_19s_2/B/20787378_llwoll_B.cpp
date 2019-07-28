#include <bits/stdc++.h>
#define rep(i,j,k) for (int i = j; i <= k; i++)
#define dow(i,j,k) for (int i = j; i >= k; i--)

using namespace std;

const int N = 305;
int n,t, c[N][N];

int main() {
	ios::sync_with_stdio(0);
	cin >> t;
	while (t--) {
		cin >> n;
		memset(c,0,sizeof(c));
		rep(i,1,n*(n-1)/2) {
			int u, v, w;
			cin >> u >> v >> w;
			c[u][v] = w;
			c[v][u] = w;
		}
		int ans = 0;
		rep(i,1,n) rep(j,i+1,n) rep(k,j+1,n) {
			ans = max(ans, c[i][j] + c[j][k] + c[k][i]);
		}
		cout << ans <<endl;
	}
}