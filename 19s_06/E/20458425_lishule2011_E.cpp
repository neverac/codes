#include <bits/stdc++.h>

using namespace std;
const int maxn=5*1e3+50;
	int dp[maxn][maxn];		
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	vector <int> Q[maxn];
	int  n;
	cin >> n;
	int a[maxn],b[maxn];
	cin >> b[1];
	int cnt = 1;
	a[1] = b[1];
	Q[b[1]].push_back(cnt);
	for (int i=2;i<=n;i++) {
		cin >> b[i];
		if (b[i] != b[i-1]) {
			a[++cnt] = b[i];
			Q[b[i]].push_back(cnt);
		}
	}		

	memset(dp,0,sizeof(dp));

	// for (int i=n;i>=2;i--)
	// 	for (int j=1;j<i;j++)
	// 		if (a[i] == a[j]){
	// 			dp[j] = max(dp[j],dp[j-1]+1);
	// 			for (int k=j+1;k<i;k++) dp[k] = max(dp[k],dp[k-1]);
	// 			break;
	// 		}else{
	// 			dp[i] = dp[i-1];
	// 		}
			memset(b,0,sizeof(b));
	for (int i=1;i<=cnt;i++) b[i]=a[cnt-i+1];
	//for (int i=1;i<=cnt;i++)cout << a[i] <<' '<<b[i]<<endl;
	for (int i=1;i<=cnt;i++)
		for (int j=1;j<=cnt;j++)
			if (a[i] == b[j]) 
				dp[i+1][j+1] = dp[i][j] +1;
			else 
				dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
			
	int maxx = -1;
	// for (int i=1;i<=cnt;i++) 
	// 	for (int j=1;j<=cnt;j++)
	// 	if (dp[i][j] > maxx) maxx = dp[i][j];
	//cout << cnt - maxx -1;
	cout << cnt-(dp[cnt+1][cnt+1]+1)/2;
}
// 15
// 4 2 4 3 1 5 5 2 1 1 2 3 2 4 5
// 10
// 4 3 5 2 1 2 3 2 4 5
// 