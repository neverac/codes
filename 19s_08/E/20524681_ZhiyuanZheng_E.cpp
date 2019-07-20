#include <bits/stdc++.h>
using namespace std;
int n;
int a[1000];
int x,y,z;
int main(){
	int T;
	cin>>T;
	while (T--){
		memset(a,0,sizeof a);
		cin>>n;
		x=0,y=0,z=0;
		for (int i=1;i<=n;i++){
			cin>>a[i];
			a[i]%=3;
			if (a[i]==0) x++;
			if (a[i]==1) y++;
			if (a[i]==2) z++;
		}
		int ans=x;
		int k=min(y,z);
		ans+=k;
		y-=k;z-=k;
		ans+=y/3+z/3;
		cout<<ans<<endl;
	}
	return 0;
}

