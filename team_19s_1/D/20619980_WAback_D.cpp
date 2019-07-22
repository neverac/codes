#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>

using namespace std;

int c[100010];
int main(){
	int T;cin>>T;
	while (T--){
		int n,m; cin>>n>>m;
		for (int i=1; i<=n; i++){
			int a,b; cin>>a>>b;
			c[i]=a+b;
		}
		sort(c+1,c+n+1);
		int ans=0;
		long long t = 1;
		for (int i=1; i<=n; i++){
			t*=c[i];
			if(t <= m)ans++;
			else break;
		}
		printf("%d\n",ans);
	}
	return 0;
}