#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[350][350],n,T,u,v,w;
int main(){
	scanf("%d",&T);
	while(T --){
		scanf("%d",&n);
		memset(a,-1,sizeof a);
		for(int i = 0;i < n*(n-1)/2;i ++){
			scanf("%d%d%d",&u,&v,&w);
			a[u][v] = w;
			a[v][u] = w;
		}
		int ans = 0;
		for(int i = 1;i <= n;i ++){
			for(int j = i+1;j <= n;j ++){
				for(int k = j+1;k <= n;k ++){
					if(a[i][j] != -1 && a[i][k] != -1 && a[j][k] != -1)
						ans = max(ans,a[i][j] + a[j][k] + a[i][k]);
				}
			}
		}
		printf("%d\n",ans);
	}
    return 0;
}
