#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char str[200010] = {0};
const int mod = 998244353;
int l = 0,r = 0;
int main(){
	int N;
	scanf("%d",&N);
	scanf("%s",str+1);
	for(int i = 2;i <= N;i++){
		if(str[i] == str[i-1])l++;
		else break;
	}
	for(int i = N-1;i >= 1;i--){
		if(str[i+1] == str[i])r++;
		else break;
	}
	l++;r++;
	if(l == N){
		printf("%lld\n",(1LL*N*(N+1)/2) % mod);
		return 0;
	}
	if(str[1] == str[N]){
		printf("%lld\n",1LL*(l + 1) * (r+1) % mod);
	}
	else{
		long long ans = 0;
		ans = l+1 + r;
		printf("%lld\n",ans);
	}
	return 0;
} 