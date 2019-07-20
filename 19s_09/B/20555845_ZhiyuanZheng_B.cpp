#include <bits/stdc++.h>
using namespace std;
int n;
const int maxn=2*1e5+10;
const long long MOD = 998244353;
int main(){
	string s;
	cin>>n;
	cin>>s;
	char f=s[0];
	char e=s[n-1];
	int i=0,j=n-1;
	long long cx=0,cy=0,ans=0;
	while (s[i]==f) i++,cx++;
	if (i==n){
		ans=1LL*((n+1)*n/2)%MOD;
		cout<<ans%MOD<<endl;
		return 0;
	}
	while (s[j]==e) j--,cy++;
	if (f==e){
		ans=1LL*(cx+1)*(cy+1)%MOD;
	}else ans=1LL*(cx+1+cy)%MOD;
	cout<<ans%MOD<<endl;
	return 0;
}

