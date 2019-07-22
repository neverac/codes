#include <bits/stdc++.h>
using namespace std;
int a[110],b[110];
int main(){
	int T;
	cin>>T;
	while (T--){
		int n,m;
		cin>>n>>m;
		int ans=0;
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		for (int i=1;i<=n;i++){
			cin>>a[i]>>b[i];
		}
		sort(b+1,b+1+n);
		for (int i=1;i<=n;i++){
			if (m/(b[i]+a[i])>0) m=m/(b[i]+a[i]),ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}

