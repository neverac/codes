#include <iostream>
#include <cstring>
using namespace std;
int n;
int a[400][400];
int main(){
	int T;
	cin>>T;
	while (T--){
		memset(a,0,sizeof a);
		cin>>n;
		for (int i=1;i<=n*(n-1)/2;i++){
			int x,y,z;
			cin>>x>>y>>z;
			a[x][y]=z;
			a[y][x]=z;
		}
		int ans=0;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				for (int k=1;k<=n;k++){
					if (i!=j&&i!=k&&j!=k)ans=max(ans,a[i][j]+a[j][k]+a[k][i]);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}