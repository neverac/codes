#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<string>
#include<iomanip>
#include<queue>

using namespace std;

#define N 200020
#define M 998244353
typedef long long LL;
char s[N];
int n;

int main(){
	cin>>n;
	scanf("%s", s + 1);
	LL i,j,k,t1,t2;
	t1 = 1;
	while(s[t1 + 1] == s[t1]  && t1 < n){
		t1++;
	}
	t2 = n;
	while(s[t2 - 1] == s[t2] && t2 > 1){
		t2--;
	}
	t2 = n - t2 + 1;
	//cout<<t1<<' '<<t2<<endl;
	LL ans = 1LL;
	//ans += (n - 1LL) * 2LL;
	ans += (t2 + t1);
	ans %= M;
	if(s[1] == s[n]){
		ans += ((t1 * t2) % M);
		ans = ans % M;
	}
	printf("%lld\n", ans);	
	return 0;
}
