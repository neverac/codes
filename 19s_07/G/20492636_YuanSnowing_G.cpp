#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[1050][1050],n,i,j,ma;
bool vis[1050][1050];
void sea(int x,int y,int r){
	bool ok = true;
	ma = max(ma,r);
	if(x+r > n || y+r > n) return;
	for(int i = x;i <= x + r;i ++){
		//vis[i][y+r] = true;
		if(a[i][y+r] != a[i][y+r-1] +1 ){
			ok  = false;
			for(int j = x;j <= i;j ++)
				for(int k = y;k <= y+r-1; k ++)
					//cout << j<<" " << k <<endl,
					vis[j][k] = true;
			break;
		}
	}
	if(ok){
		for(int j = y;j <= y + r;j ++){
			//vis[x+r][j] = true;
			if(a[x+r][j] != a[x+r-1][j] +1){
				ok = false;
				for(int i = x;i <= x+r-1;i ++)
				for(int k = y;k <= j; k ++)
					//cout << i<<" " << k <<endl,
					vis[i][k] = true;
				break;
			}
		}
	}
	if(ok) sea(x,y,r+1);
}
int main(){
	scanf("%d",&n);
	ma = 1;
	memset(vis,0,sizeof vis);
	for(i = 1;i <= n;i ++)
		for(j = 1;j <=n;j ++)
			scanf("%d",&a[i][j]);
	for(i = 1;i <= n;i ++)
		for(j = 1;j <=n;j ++)
			if(!vis[i][j]) sea(i,j,1);
	
printf("%d\n",ma);
    return 0;
}
/*
4
1 2 3 4
2 3 4 5
4 4 5 6
4 4 5 6


*/