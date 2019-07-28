#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
int n,x1,yy1,x2,y2;
int a[maxn][maxn];
int vis[maxn][maxn];
bool over(int x,int y){
	// cout << x<<' '<<y<<' '<<a[x][y]<<endl;
	if (x == 0 || y == 0 || x >= n+1 ||y >= n+1) {
		
		return true;

	}
	if (a[x][y] == 1|| a[x][y]==2|| a[x][y] == 3) return true;
	// cout << "fuck"<<endl;
	return false;
}
void dfs(int x,int y,int col){
	if (vis[x][y] || over(x,y)) return;
	// cout << x  << ' '<<y<< ' ' << col <<endl;
	vis[x][y] = 1;
	a[x][y] = col;
	dfs(x-1,y,col),dfs(x,y+1,col),dfs(x,y-1,col),dfs(x+1,y,col);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	cin >> x1 >> yy1;
	cin >> x2 >> y2;

	for (int i=1;i<=n;i++){
		string s;
		cin >> s;
		// cout << s<<endl;

		for (int j=0;j<n;j++) a[i][j+1] = s[j] -'0';
	}
	
	// for (int i=1;i<=n;i++) {
	// 	for (int j=1;j<=n;j++)
	// 		cout << a[i][j];
	// 	cout << endl;
	// }

	// cout << over(1,1) <<a[1][1]<< endl;
	
	memset(vis,0,sizeof(vis));
	dfs(x1,yy1,2);
	if (a[x2][y2] == 2) {
		cout << 0<<endl;
		return 0;
	}
	memset(vis,0,sizeof(vis));
	dfs(x2,y2,3);
	// cout << endl;
	// for (int i=1;i<=n;i++) {
	// 	for (int j=1;j<=n;j++)
	// 		cout << a[i][j];
	// 	cout << endl;
	// }
	long long  ans = 0x3f3f3f3f;
	for(int i=1;i<=n;i++)
		for (int j = 1;j<=n;j++)
			if (a[i][j] == 2)
				for (int p=1;p<=n;p++)
					for (int q=1;q<=n;q++)
						if (a[p][q] == 3)
							ans = min(1LL*(abs(i-p)*abs(i-p)+abs(j-q)*abs(j-q)),ans);
	cout << ans;

}
