#include <bits/stdc++.h>
using namespace std;
int n,m,e;
bool gh[1010][1010];
int p[1010];
bool vis[1010];
bool find(int i){
	for (int j=1;j<=m;j++){
		if (gh[i][j]&&!vis[j]) {
			vis[j]=true;
			if (p[j]==0||find(p[j])){
				p[j]=i;
				return true;
			}
		}
	}
	return false;
}
int main(){
	cin>>n;
	while (n!=0){
	cin>>m>>e;
	memset(gh,0,sizeof gh);
	memset(p,0,sizeof p);
	for (int i=1;i<=e;i++){
		int x,y;
		cin>>x>>y;
		x++;y++;
		gh[x][y]=true;
	}
	int ans=0;
	for (int i=1;i<=n;i++){
		memset(vis,0,sizeof vis);
		if (find(i)) ans++;
	}
	cout<<ans<<endl;
	cin>>n;
	}
	return 0;
}

