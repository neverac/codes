#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
LL K,A,B;
int main(){
	scanf("%lld%lld%lld",&K,&A,&B);
	if(A >= B){
		printf("%lld\n",K+1);
		return 0;
	}
	LL tmp = A - 1;
	LL rest = K - tmp;
	LL ans = rest/2 * (B-A) + A + (rest & 1);
	ans = max(ans,K+1);
	printf("%lld\n",ans);
	return 0;
}