#include <iostream>
#include <queue>
#include <cstring>
const int maxn=1010;
using namespace std;
struct Node {
	int x,y;
};
queue <Node> Q;
int a[maxn][maxn],d[maxn][maxn];
int vis[maxn][maxn];
int main(){
	memset(vis,0,sizeof(vis));
	memset(d,0,sizeof(d));
	ios::sync_with_stdio(false);
	cin.tie(0);
	int h,w;
	cin >> h>>w;
	for(int i=1;i<=h;i++){
		string s;
		cin >> s;
		for (int j=0;j<w;j++) {
			if (s[j] == '#'){
				a[i][j+1] = 1;
				Q.push((Node){i,j+1});
				vis[i][j+1] = 1;
			}else a[i][j+1] = 0;
			// a[i][j+1] = s[j]=='h'?1:0;

		}
	}

	int cnt = 0;
	while (!Q.empty()){
		Node p=Q.front();
		Q.pop();
		if (p.x>1 && !vis[p.x-1][p.y]){
			d[p.x-1][p.y] = d[p.x][p.y] + 1;
			Q.push((Node){p.x-1,p.y});
			vis[p.x-1][p.y] = 1;
		}
		if (p.y>1 && !vis[p.x][p.y-1]){
			d[p.x][p.y-1] = d[p.x][p.y] + 1;
			Q.push((Node){p.x,p.y-1});
			vis[p.x][p.y-1] = 1;
		}
		if (p.x<h && !vis[p.x+1][p.y]){
			d[p.x+1][p.y] = d[p.x][p.y] + 1;
			Q.push((Node){p.x+1,p.y});
			vis[p.x+1][p.y] = 1;
		}
		if (p.y<w && !vis[p.x][p.y+1]){
			d[p.x][p.y+1] = d[p.x][p.y] + 1;
			Q.push((Node){p.x,p.y+1});
			vis[p.x][p.y+1] = 1;
		}
	}
	int ans=0;
	// for (int i=1;i<=h;i++){
	// 	for (int j=1;j<=w;j++) ans=max(ans,d[i][j]),cout << d[i][j]<<' ';
	// 	cout << endl;
	// }
	for (int i=1;i<=h;i++)
		for (int j=1;j<=w;j++) ans=max(ans,d[i][j]);
	
	cout << ans;
}