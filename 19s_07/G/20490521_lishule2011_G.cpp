#include <iostream>
#include <cstring>
using namespace std;
const int maxn=1e3+100;
int a[maxn][maxn],dp[maxn][maxn],f[maxn][maxn],n;
bool work(int r){
	int x=r*r;
	for (int i=r;i<=n;i++)
		for (int j=r;j<=n;j++)
			if (f[i][j]-f[i-r][j-r] == x) return 1;
	return 0;
}
bool pd(int x,int y){
	if (a[x][y] == a[x][y-1]+1 && a[x][y] == a[x-1][y]+1
		 && dp[x-1][y]>=dp[x-1][y-1] && dp[x][y-1]>=dp[x-1][y-1]) return 1;
	return 0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;

	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++){
			cin >> a[i][j];
		//	tz[i][j]=i==1||j==1||(a[i][j]==a[i-1][j]+1 && a[i][j-1]+1==a[i][j])?1:0;
		}
	memset(dp,0,sizeof(dp));
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
				dp[i][j]=(i == 1||j == 1)?1:(pd(i,j)?dp[i-1][j-1]+1:1);
	int ans=0;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++)
			// cout << dp[i][j]<<' ';
		// cout << endl;
			ans =max(ans,dp[i][j]);
	}
	cout << ans;
	// memset(f,0,sizeof(f));
	// for (int i=1;i<=n;i++){
	// 	for (int j=1;j<=n;j++)
	// 		f[i][j]=f[i-1][j]+f[i][j-1]-f[i-1][j-1]+tz[i][j];
	// }
	// for (int i=1;i<=n;i++) {
	// 	for (int j=1;j<=n;j++) cout <<f[i][j] <<' ';
	// 		cout << endl;
	// }
	// int l=1,r=n;
	// while(l<r){
	// 	int mid=(l+r+1)/2;
	// 	if (work(mid)) l=mid;
	// 	else r=mid-1;
	// }
	// cout << r;
}
// 5
// 0 0 0 0 0
// 0 1 2 3 0
// 0 2 3 4 0
// 0 3 4 5 0
// 0 0 0 0 0