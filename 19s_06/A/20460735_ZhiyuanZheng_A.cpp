#include <bits/stdc++.h>
using namespace std;
long long a[1000000],s[1000000],k[1000000];
int main(){
	long long n,b;
	cin>>n>>b;
	int cnt=0;
	long long bb=b;
	long long ans=1e18;
	for (int i=2;i<=sqrt(b);i++){
		if (b%i==0) {
			a[++cnt]=i;
			long long l=b;
			while (l%i==0){
				l/=i;
				k[cnt]++;
			}
			b=l;
		}
	}
	if (b!=1) a[++cnt]=b,k[cnt]++;
	for (int i=1;i<=cnt;i++){
		long long kk=0,ll=n;
		while (ll!=0){
			ll/=a[i];
			kk+=ll;
		}
		ans=min(ans,kk/k[i]);
	}
	cout<<ans<<endl;
	return 0;
}


