#include <bits/stdc++.h>
using namespace std;
int n;
int f[1010][1010];
int gh[1010][1010];

bool check(int x,int y){
	if (gh[x][y]==gh[x-1][y]+1&&gh[x][y]==gh[x][y-1]+1&&gh[x][y]==gh[x-1][y-1]+2)
		return true;
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			cin>>gh[i][j];
	memset(f,0,sizeof f);
	for (int i=1;i<=n;i++){
		f[1][i]=1;
		f[i][1]=1;
	}
	for (int i=2;i<=n;i++){
		for (int j=2;j<=n;j++){
			if (check(i,j)) f[i][j]=f[i-1][j-1]+1;else f[i][j]=1; 
		}
	}
	int ans=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			ans=max(ans,f[i][j]);
	cout<<ans<<endl; 
	return 0;
}

